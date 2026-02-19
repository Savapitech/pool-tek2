pub fn flying_sequence(mut countdown: u32, ignition: u32, secondary_activation: u32, thrust_duration: u32) {
    if ignition > countdown || secondary_activation < 30 {
        println!("Wrong flying sequence, go back to the lab !");
        return;
    }

    while countdown > 0 {
        if countdown == ignition {
            println!("Main engine ignition");
        }
        println!("Liftoff in {}...", countdown);
        countdown -= 1;
    }

    println!("Liftoff ! We have liftoff !");

    let main_cutoff = secondary_activation - 10;
    let main_decouple = main_cutoff + 1;
    let secondary_cutoff = secondary_activation + thrust_duration;

    let mut t: u32 = 10;
    while t <= secondary_cutoff {
        if t == main_cutoff {
            println!("T+{} : Main engine cutoff", t);
        } else if t == main_decouple {
            println!("T+{} : Main engine decoupling", t);
        } else if t == secondary_activation {
            println!("T+{} : Secondary engines ignition", t);
        } else if t == secondary_cutoff {
            println!("T+{} : Secondary engines cutoff. We're in orbit !", t);
            break;
        }
        if t % 10 == 0 {
            println!("T+{} : Everything is fine", t);
        }
        t += 1;
    }
}
