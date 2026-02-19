use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();
    let mut energy: i32 = args[1].parse().unwrap();
    let mut temp: i32 = args[2].parse().unwrap();

    let mut i = 3;
    while i < args.len() {
        let element = args[i].to_lowercase();
        let weight: i32 = args[i + 1].parse().unwrap();

        match element.as_str() {
            "uranium" => {
                energy += 40 * weight;
                temp += 10 * weight;
                println!("Processing: Uranium ({}kg)", weight);
            }

            "plutonium" => {
                energy += 90 * weight;
                temp += 60 * weight;
                println!("Processing: Plutonium ({}kg)", weight);
            }

            "oldboot" => {
                energy += 20 * weight;
                temp += 5 * weight;
                println!("Processing: OldBoot ({}kg)", weight);
            }

            "unknown" => {
                if temp % 2 == 0 {
                    energy += 400 * weight;
                } else {
                    energy -= 150 * weight;
                }
                temp += 20 * weight;
                println!("Processing: Unknown ({}kg)", weight);
            }
            _ => {
                println!("Error: Unknown element");
                return;
            }
        }

        println!("Reactor Stats: Energy {}, Temp {}", energy, temp);

        if temp > 800 {
            println!("CRITICAL MELTDOWN!");
            return;
        }

        if energy >= 2000 {
            println!("Orbit achieved!");
            return;
        }

        i += 2;
    }

    println!("Out of fuel. We drift into the void...");
}
