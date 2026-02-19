pub fn compute_survivable_days(water_quantity: f32, water_cycles: u32, food_quantity: f32, nb_crew: u32) -> u32 {
    if nb_crew == 0 {
        return 0;
    }

    let total_water = water_quantity * water_cycles as f32;
    let water_per_day = nb_crew as f32 * 2.0;
    let water_days = (total_water / water_per_day).floor() as u32;

    let food_per_day = nb_crew as f32 * 0.5;
    let food_days = (food_quantity / food_per_day).floor() as u32;

    println!("If the mission can embark {}L of water, {}kg of food and the water recycler can do {} water cycles... With {} crew members, there is enough water for {} day(s) and enough food for {} day(s).", water_quantity, food_quantity, water_cycles, nb_crew, water_days, food_days);

    water_days.min(food_days)
}

fn main() {
    println!("Survivable days : {}", compute_survivable_days(10.0, 2, 20.3, 5));
    println!("Survivable days : {}", compute_survivable_days(14.0, 10, 56.3, 7));
    println!("Survivable days : {}", compute_survivable_days(12.0, 26, 37.5, 3));
}
