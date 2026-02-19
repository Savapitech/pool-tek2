use std::fmt;
use std::cmp::Ordering;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MissionState {
    Planned,
    InProgress,
    Completed,
    Failed,
}

impl fmt::Display for MissionState {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let state_str = match self {
            MissionState::Planned => "PLANNED",
            MissionState::InProgress => "IN PROGRESS",
            MissionState::Completed => "COMPLETED",
            MissionState::Failed => "FAILED",
        };
        write!(f, "{}", state_str)
    }
}

impl PartialOrd for MissionState {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Ord for MissionState {
    fn cmp(&self, other: &Self) -> Ordering {
        let priority = |state: &MissionState| -> u8 {
            match state {
                MissionState::Failed => 3,
                MissionState::InProgress => 2,
                MissionState::Planned => 1,
                MissionState::Completed => 0,
            }
        };
        priority(self).cmp(&priority(other))
    }
}

#[derive(Debug, Clone, PartialEq)]
pub struct Rover {
    pub name: String,
    pub fuel_level: u8,
    pub map_sectors: Vec<u32>,
}

impl fmt::Display for Rover {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{} (Fuel: {}%)", self.name, self.fuel_level)
    }
}

#[derive(Debug)]
pub struct Mission {
    pub mission_name: String,
    pub rover: Rover,
    pub state: MissionState,
}

impl fmt::Display for Mission {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(
            f,
            "[{}] {}\n  > Assigned Rover: {}\n  > Map Coverage: {} sectors",
            self.state,
            self.mission_name,
            self.rover,
            self.rover.map_sectors.len()
        )
    }
}

impl PartialEq for Mission {
    fn eq(&self, other: &Self) -> bool {
        self.mission_name == other.mission_name
    }
}
