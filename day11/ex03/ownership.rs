pub struct Chest {
    pub helmet: u32,
    pub suit: u32,
}

pub fn add_title(name: &String) -> String {
    format!("Astronaut {}", name)
}

pub fn sign_contract(name: &String) -> String {
    format!("I am honored to join the space program of The Union and I am willing to risk my life to explore space. Therefore, I renounce every right I have to sue The Union in the event of my death.\nSigned: {}", name)
}

pub fn sign_press_declaration(name: &String) -> String {
    format!("I am thrilled that I have been chosen in the space program of The Union. I will make The Union and my family proud by being a good astronaut, dedicated to the exploration of space. Cheers  nd see you on Venus !\nSigned: {}", name)
}

pub fn take_helmet(chest: &mut Chest, qty: u32) {
    chest.helmet -= qty;
}

pub fn take_suit(chest: &mut Chest, qty: u32) {
    chest.suit -= qty;
}
