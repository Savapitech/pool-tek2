#[derive(Debug, PartialEq)]
pub enum FlightStatus {
    OnTime,
    Delayed(u32),
    Cancelled(String),
}

#[derive(Debug)]
pub struct Flight {
    pub id: String,
    pub destination: String,
    pub time: u32,
    pub status: FlightStatus,
}

pub fn parse_flight(line: &str) -> Result<Flight, String> {
    let parts: Vec<&str> = line.split(',').collect();
    
    if parts.len() != 4 {
        return Err(String::from("Bad format"));
    }
    
    let id = parts[0].to_string();
    let destination = parts[1].to_string();
    
    let time = parts[2].parse::<u32>().map_err(|_| String::from("Bad time"))?;
    
    let status_str = parts[3];
    let status = if status_str == "ONTIME" {
        FlightStatus::OnTime
    } else if status_str.starts_with("DELAYED ") {
        let delay_str = status_str.trim_start_matches("DELAYED ");
        let delay = delay_str
            .parse::<u32>()
            .map_err(|_| String::from("Bad delay"))?;
        FlightStatus::Delayed(delay)
    } else if status_str.starts_with("CANCELLED ") {
        let reason = status_str.trim_start_matches("CANCELLED ");
        FlightStatus::Cancelled(reason.to_string())
    } else {
        return Err(String::from("Unknown status"));
    };
    
    Ok(Flight {
        id,
        destination,
        time,
        status,
    })
}

pub fn build_schedule(raw_logs: Vec<&str>) -> Vec<Flight> {
    let mut flights = Vec::new();
    
    for log in raw_logs {
        if let Ok(flight) = parse_flight(log) {
            flights.push(flight);
        }
    }
    
    flights.sort_by_key(|f| f.time);
    
    flights
}

#[cfg(test)]
pub mod tests {
    use super::*;

    #[test]
    fn test_parse_flight_ontime() {
        let result = parse_flight("SA-202,Mars,1430,ONTIME");
        assert!(result.is_ok());
        let flight = result.unwrap();
        assert_eq!(flight.id, "SA-202");
        assert_eq!(flight.destination, "Mars");
        assert_eq!(flight.time, 1430);
        assert_eq!(flight.status, FlightStatus::OnTime);
    }

    #[test]
    fn test_parse_flight_delayed() {
        let result = parse_flight("XF-99,Jupiter,1800,DELAYED 60");
        assert!(result.is_ok());
        let flight = result.unwrap();
        assert_eq!(flight.status, FlightStatus::Delayed(60));
    }

    #[test]
    fn test_parse_flight_cancelled() {
        let result = parse_flight("ER-01,Earth,2500,CANCELLED Engine Failure");
        assert!(result.is_ok());
        let flight = result.unwrap();
        assert_eq!(flight.status, FlightStatus::Cancelled(String::from("Engine Failure")));
    }

    #[test]
    fn test_parse_flight_bad_format() {
        let result = parse_flight("BAD-LINE,Nowhere,0000");
        assert!(result.is_err());
        assert_eq!(result.unwrap_err(), "Bad format");
    }

    #[test]
    fn test_parse_flight_bad_time() {
        let result = parse_flight("ZZ-99,Pluto,invalid,ONTIME");
        assert!(result.is_err());
        assert_eq!(result.unwrap_err(), "Bad time");
    }

    #[test]
    fn test_parse_flight_unknown_status() {
        let result = parse_flight("XX-01,Mars,1200,UNKNOWN");
        assert!(result.is_err());
        assert_eq!(result.unwrap_err(), "Unknown status");
    }

    #[test]
    fn test_build_schedule_sorted() {
        let logs = vec![
            "SA-202,Mars,1430,ONTIME",
            "TR-55,Venus,1200,ONTIME",
            "XF-99,Jupiter,1800,DELAYED 60",
        ];
        let schedule = build_schedule(logs);
        assert_eq!(schedule.len(), 3);
        assert_eq!(schedule[0].time, 1200);
        assert_eq!(schedule[1].time, 1430);
        assert_eq!(schedule[2].time, 1800);
    }

    #[test]
    fn test_build_schedule_filters_invalid() {
        let logs = vec![
            "SA-202,Mars,1430,ONTIME",
            "INVALID",
            "TR-55,Venus,1200,ONTIME",
        ];
        let schedule = build_schedule(logs);
        assert_eq!(schedule.len(), 2);
    }
}
