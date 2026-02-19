pub fn calculate_average_temperature(readings: &[f64]) -> Option<f64> {
    let valid_readings: Vec<f64> = readings
        .iter()
        .filter(|&&temp| temp >= -273.15)
        .map(|&temp| temp + 2.0)
        .collect();
    
    if valid_readings.is_empty() {
        None
    } else {
        let sum: f64 = valid_readings.iter().sum();
        Some(sum / valid_readings.len() as f64)
    }
}
