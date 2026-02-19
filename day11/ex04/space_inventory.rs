#[derive(Clone)]
pub enum ItemType {
    Tool,
    Weapon(u32),
}

pub struct Item {
    pub name: String,
    pub item_type: ItemType,
    pub price: f32,
    pub usage: u8,
}

pub fn get_damage(item: &Item) -> u32 {
    match item.item_type {
        ItemType::Weapon(dmg) => dmg,
        ItemType::Tool => 0,
    }
}

pub fn is_used(item: &Item) -> bool {
    item.usage < 25
}

pub fn use_item(item: &mut Item, percent: u8) {
    if item.usage > percent {
        item.usage -= percent;
    } else {
        item.usage = 0;
    }

    if item.usage < 25 {
        item.price *= 0.25;
    }
}

pub fn harmonize_price(a: &mut Item, b: &mut Item) {
    let max_price = a.price.max(b.price);
    a.price = max_price;
    b.price = max_price;
}

