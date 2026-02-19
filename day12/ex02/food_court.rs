#[derive(Debug, PartialEq)]
pub struct Recipe {
    pub name: String,
    pub ingredients: Vec<String>,
}

pub fn get_ingredient_quantity(ingredient: &str) -> Result<usize, String> {
    match ingredient {
        "Space Bacon" => Ok(42),
        "Dehydrated Eggs" => Ok(120),
        "Soy Milk" => Ok(5),
        "Antimatter" => panic!("BOOM! The kitchen exploded!"),
        "Recycled Water" => Err(String::from("Machine broken")),
        _ => Err(String::from("Food not found")),
    }
}

pub fn resolve_recipe(name: &str) -> Result<Recipe, String> {
    match name {
        "Space Omelette" => Ok(Recipe {
            name: String::from("Space Omelette"),
            ingredients: vec![String::from("Space Bacon"), String::from("Dehydrated Eggs")],
        }),
        "Corpse Reviver" => Ok(Recipe {
            name: String::from("Corpse Reviver"),
            ingredients: vec![String::from("Soy Milk"), String::from("Recycled Water")],
        }),
        "Quantum Brownie" => Ok(Recipe {
            name: String::from("Quantum Brownie"),
            ingredients: vec![String::from("Space Bacon"), String::from("Antimatter")],
        }),
        _ => Err(String::from("Meal not on menu")),
    }
}

pub fn check_availability(recipe: &Recipe) -> Result<String, String> {
    for ingredient in &recipe.ingredients {
        get_ingredient_quantity(ingredient)?;
    }
    Ok(String::from("All ingredients available"))
}

pub fn cook_meal(order: &str) -> Result<String, String> {
    let recipe = resolve_recipe(order)?;
    check_availability(&recipe)?;
    Ok(format!("The {} is ready!", recipe.name))
}

#[cfg(test)]
pub mod tests {
    use super::*;

    #[test]
    fn test_get_ingredient_space_bacon() {
        assert_eq!(get_ingredient_quantity("Space Bacon"), Ok(42));
    }

    #[test]
    fn test_get_ingredient_dehydrated_eggs() {
        assert_eq!(get_ingredient_quantity("Dehydrated Eggs"), Ok(120));
    }

    #[test]
    fn test_get_ingredient_not_found() {
        assert_eq!(get_ingredient_quantity("Pizza"), Err(String::from("Food not found")));
    }

    #[test]
    fn test_get_ingredient_machine_broken() {
        assert_eq!(get_ingredient_quantity("Recycled Water"), Err(String::from("Machine broken")));
    }

    #[test]
    fn test_resolve_recipe_space_omelette() {
        let recipe = resolve_recipe("Space Omelette").unwrap();
        assert_eq!(recipe.name, "Space Omelette");
        assert_eq!(recipe.ingredients.len(), 2);
    }

    #[test]
    fn test_resolve_recipe_not_on_menu() {
        assert_eq!(resolve_recipe("Burger"), Err(String::from("Meal not on menu")));
    }

    #[test]
    fn test_cook_meal_success() {
        let result = cook_meal("Space Omelette");
        assert!(result.is_ok());
        assert_eq!(result.unwrap(), "The Space Omelette is ready!");
    }

    #[test]
    fn test_cook_meal_machine_broken() {
        let result = cook_meal("Corpse Reviver");
        assert!(result.is_err());
        assert_eq!(result.unwrap_err(), "Machine broken");
    }
}
