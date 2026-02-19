use std::collections::HashMap;

#[derive(Debug, PartialEq)]
pub struct Stock {
    pub quantity: u32,
    pub total_value: u32,
}

pub fn consolidate_inventory(orders: &[(&str, u32, u32)]) -> HashMap<String, Stock> {
    let mut inventory: HashMap<String, Stock> = HashMap::new();
    
    for &(name, quantity, price_per_unit) in orders {
        if quantity == 0 && !inventory.contains_key(name) {
            continue;
        }
        
        if quantity == 0 {
            continue;
        }
        
        let value = quantity * price_per_unit;
        
        inventory
            .entry(String::from(name))
            .and_modify(|stock| {
                stock.quantity += quantity;
                stock.total_value += value;
            })
            .or_insert(Stock {
                quantity,
                total_value: value,
            });
    }
    
    inventory
}

#[cfg(test)]
pub mod tests {
    use super::*;

    #[test]
    fn test_consolidate_single_item() {
        let orders = [("Iron", 100, 5)];
        let inventory = consolidate_inventory(&orders);
        assert_eq!(inventory.len(), 1);
        let stock = inventory.get("Iron").unwrap();
        assert_eq!(stock.quantity, 100);
        assert_eq!(stock.total_value, 500);
    }

    #[test]
    fn test_consolidate_multiple_same_item() {
        let orders = [("Iron", 100, 5), ("Iron", 50, 5)];
        let inventory = consolidate_inventory(&orders);
        assert_eq!(inventory.len(), 1);
        let stock = inventory.get("Iron").unwrap();
        assert_eq!(stock.quantity, 150);
        assert_eq!(stock.total_value, 750);
    }

    #[test]
    fn test_consolidate_different_items() {
        let orders = [("Iron", 100, 5), ("Gold", 10, 100)];
        let inventory = consolidate_inventory(&orders);
        assert_eq!(inventory.len(), 2);
        assert!(inventory.contains_key("Iron"));
        assert!(inventory.contains_key("Gold"));
    }

    #[test]
    fn test_consolidate_zero_quantity_new_item() {
        let orders = [("Iron", 0, 5)];
        let inventory = consolidate_inventory(&orders);
        assert_eq!(inventory.len(), 0);
    }

    #[test]
    fn test_consolidate_zero_quantity_existing_item() {
        let orders = [("Iron", 100, 5), ("Iron", 0, 5)];
        let inventory = consolidate_inventory(&orders);
        let stock = inventory.get("Iron").unwrap();
        assert_eq!(stock.quantity, 100);
        assert_eq!(stock.total_value, 500);
    }

    #[test]
    fn test_consolidate_different_prices() {
        let orders = [("Sapphire", 10, 500), ("Sapphire", 5, 600)];
        let inventory = consolidate_inventory(&orders);
        let stock = inventory.get("Sapphire").unwrap();
        assert_eq!(stock.quantity, 15);
        assert_eq!(stock.total_value, 8000);
    }

    #[test]
    fn test_consolidate_empty() {
        let orders: [(&str, u32, u32); 0] = [];
        let inventory = consolidate_inventory(&orders);
        assert_eq!(inventory.len(), 0);
    }
}
