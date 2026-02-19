pub struct Report {
    pub sample_count: usize,
    pub total_energy: f64,
}

pub fn fusion_processing(temp_log: &[&str], rpm_log: &[u32]) -> Report {
    let valid_temps: Vec<f64> = temp_log
        .iter()
        .filter_map(|s| s.parse::<f64>().ok())
        .collect();
    
    let valid_rpms: Vec<f64> = rpm_log
        .iter()
        .filter(|&&rpm| rpm > 2500)
        .map(|&rpm| rpm as f64)
        .collect();
    
    let (sample_count, total_energy) = valid_temps
        .iter()
        .zip(valid_rpms.iter())
        .map(|(temp, rpm)| {
            let energy = temp / rpm;
            if energy.is_infinite() || energy > 100.0 {
                100.0
            } else {
                energy
            }
        })
        .fold((0, 0.0), |(count, sum), energy| (count + 1, sum + energy));
    
    Report {
        sample_count,
        total_energy,
    }
}
