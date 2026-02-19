#[derive(Debug, PartialEq)]
pub struct Coordinates {
    pub x: i32,
    pub y: i32,
    pub z: i32,
}

pub fn get_place(name: &str) -> Option<Coordinates> {
    match name {
        "Earth" => Some(Coordinates { x: 0, y: 0, z: 0 }),
        "Mars" => Some(Coordinates { x: 15, y: 22, z: 110 }),
        "Jupiter" => Some(Coordinates { x: 88, y: 12, z: -4 }),
        _ => None,
    }
}

pub fn analyze_transport_method(option: Option<Coordinates>) -> String {
    match option {
        Some(coords) => format!("Teleporting to {},{},{}", coords.x, coords.y, coords.z),
        None => String::from("No destination available"),
    }
}

pub fn risky_teleport(option: Option<Coordinates>) -> String {
    let coords = option.unwrap();
    format!("Teleporting to {},{},{}", coords.x, coords.y, coords.z)
}

#[cfg(test)]
pub mod tests {
    use super::*;

    #[test]
    fn test_get_place_earth() {
        let coords = get_place("Earth").unwrap();
        assert_eq!(coords.x, 0);
        assert_eq!(coords.y, 0);
        assert_eq!(coords.z, 0);
    }

    #[test]
    fn test_get_place_mars() {
        let coords = get_place("Mars").unwrap();
        assert_eq!(coords.x, 15);
        assert_eq!(coords.y, 22);
        assert_eq!(coords.z, 110);
    }

    #[test]
    fn test_get_place_jupiter() {
        let coords = get_place("Jupiter").unwrap();
        assert_eq!(coords.x, 88);
        assert_eq!(coords.y, 12);
        assert_eq!(coords.z, -4);
    }

    #[test]
    fn test_get_place_unknown() {
        let result = get_place("Unknown");
        assert!(result.is_none());
    }

    #[test]
    fn test_analyze_transport_method_some() {
        let coords = get_place("Earth");
        let result = analyze_transport_method(coords);
        assert_eq!(result, "Teleporting to 0,0,0");
    }

    #[test]
    fn test_analyze_transport_method_none() {
        let result = analyze_transport_method(None);
        assert_eq!(result, "No destination available");
    }

    #[test]
    fn test_risky_teleport_success() {
        let result = risky_teleport(get_place("Mars"));
        assert_eq!(result, "Teleporting to 15,22,110");
    }

    #[test]
    #[should_panic]
    fn test_risky_teleport_panic() {
        risky_teleport(None);
    }
}
