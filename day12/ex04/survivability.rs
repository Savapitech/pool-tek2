#[derive(Debug, PartialEq)]
pub struct ShipAssessment {
    pub water_quantity: f32,
    pub water_cycles: u32,
    pub food_quantity: f32,
}

#[derive(Debug, PartialEq)]
pub struct StudyResult {
    pub rock_name: String,
    pub reachable: bool,
    pub ship_index: usize,
}

pub fn compute_survivable_days(needs: &ShipAssessment, nb_crew: u32) -> u32 {
    let water_per_day = nb_crew as f32 * 3.0;
    
    let total_water = needs.water_quantity * (1 + needs.water_cycles) as f32;
    
    let days_water = total_water / water_per_day;
    
    let days_food = needs.food_quantity / nb_crew as f32;
    
    days_water.min(days_food) as u32
}

pub fn study_ships(
    ships: &[ShipAssessment],
    rocks_to_visit: &[(String, u32)],
    rock: String,
    nb_crew: u32,
) -> StudyResult {
    let rock_distance = rocks_to_visit
        .iter()
        .find(|(name, _)| name == &rock)
        .map(|(_, distance)| *distance);
    
    if rock_distance.is_none() {
        return StudyResult {
            rock_name: String::from("Error"),
            reachable: false,
            ship_index: 0,
        };
    }
    
    let distance = rock_distance.unwrap();
    
    let mut best_index = 0;
    let mut best_days = 0;
    
    for (index, ship) in ships.iter().enumerate() {
        let survivable_days = compute_survivable_days(ship, nb_crew);
        if survivable_days >= distance {
            return StudyResult {
                rock_name: rock.clone(),
                reachable: true,
                ship_index: index,
            };
        }
        if survivable_days > best_days {
            best_days = survivable_days;
            best_index = index;
        }
    }
    
    StudyResult {
        rock_name: rock,
        reachable: false,
        ship_index: best_index,
    }
}

#[cfg(test)]
pub mod tests {
    use super::*;

    #[test]
    fn test_compute_survivable_days_water_limit() {
        let ship = ShipAssessment {
            water_quantity: 100.0,
            water_cycles: 0,
            food_quantity: 10000.0,
        };
        assert_eq!(compute_survivable_days(&ship, 3), 11);
    }

    #[test]
    fn test_compute_survivable_days_food_limit() {
        let ship = ShipAssessment {
            water_quantity: 1000.0,
            water_cycles: 100,
            food_quantity: 30.0,
        };
        assert_eq!(compute_survivable_days(&ship, 3), 10);
    }

    #[test]
    fn test_compute_survivable_days_with_cycles() {
        let ship = ShipAssessment {
            water_quantity: 600.0,
            water_cycles: 25,
            food_quantity: 3020.0,
        };
        assert_eq!(compute_survivable_days(&ship, 3), 1006);
    }

    #[test]
    fn test_study_ships_rock_not_found() {
        let ships = vec![ShipAssessment {
            water_quantity: 100.0,
            water_cycles: 10,
            food_quantity: 500.0,
        }];
        let rocks = vec![(String::from("Mars"), 100)];
        let result = study_ships(&ships, &rocks, String::from("Venus"), 3);
        assert_eq!(result.rock_name, "Error");
        assert_eq!(result.reachable, false);
    }

    #[test]
    fn test_study_ships_reachable() {
        let ships = vec![ShipAssessment {
            water_quantity: 600.0,
            water_cycles: 25,
            food_quantity: 3020.0,
        }];
        let rocks = vec![(String::from("Mars"), 100)];
        let result = study_ships(&ships, &rocks, String::from("Mars"), 3);
        assert_eq!(result.rock_name, "Mars");
        assert_eq!(result.reachable, true);
        assert_eq!(result.ship_index, 0);
    }

    #[test]
    fn test_study_ships_not_reachable() {
        let ships = vec![ShipAssessment {
            water_quantity: 10.0,
            water_cycles: 0,
            food_quantity: 10.0,
        }];
        let rocks = vec![(String::from("Mars"), 1000)];
        let result = study_ships(&ships, &rocks, String::from("Mars"), 3);
        assert_eq!(result.rock_name, "Mars");
        assert_eq!(result.reachable, false);
    }

    #[test]
    fn test_study_ships_first_reachable() {
        let ships = vec![
            ShipAssessment {
                water_quantity: 1000.0,
                water_cycles: 50,
                food_quantity: 5000.0,
            },
            ShipAssessment {
                water_quantity: 10.0,
                water_cycles: 0,
                food_quantity: 10.0,
            },
        ];
        let rocks = vec![(String::from("Mars"), 200)];
        let result = study_ships(&ships, &rocks, String::from("Mars"), 3);
        assert_eq!(result.ship_index, 0);
        assert_eq!(result.reachable, true);
    }
}
