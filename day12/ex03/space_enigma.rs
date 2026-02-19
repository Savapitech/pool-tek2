pub enum Message {
    ClearString(String),
    DigitalCode(u32),
    Encrypted(String, u32),
}

pub enum SecurityClass {
    Civilian,
    Diplomatic,
    Military,
}

pub struct Transmission {
    pub message: Message,
    pub security: SecurityClass,
    pub signal_strength: u8,
}

pub fn solve_enigma(transmission: Transmission, daily_key: u32) -> Result<String, String> {
    if transmission.signal_strength == 0 {
        return Err(String::from("Signal lost"));
    }
    if transmission.signal_strength < 20 {
        return Err(String::from("Signal too weak"));
    }

    match transmission.security {
        SecurityClass::Military => {
            if daily_key != 4242 {
                return Err(String::from("Security Breach: Invalid Key"));
            }
        }
        _ => {}
    }

    let decoded = match transmission.message {
        Message::ClearString(s) => {
            if s == "Bomb" {
                return Err(String::from("Panic: Bomb detected"));
            }
            s
        }
        Message::DigitalCode(code) => match code {
            404 => String::from("Not Found"),
            200 => String::from("OK"),
            _ => format!("Code: {}", code),
        },
        Message::Encrypted(content, key_id) => {
            if key_id == daily_key {
                content
            } else {
                return Err(String::from("Encryption Error: Wrong Key"));
            }
        }
    };

    let mut complexity_score: i32 = 0;
    for ch in decoded.chars() {
        if ch.is_alphabetic() {
            complexity_score += 1;
        } else if ch.is_digit(10) {
            complexity_score -= 1;
        }
    }

    if complexity_score < 0 {
        return Err(String::from("Artificial Noise"));
    }

    Ok(decoded)
}

#[cfg(test)]
pub mod tests {
    use super::*;

    #[test]
    fn test_signal_lost() {
        let t = Transmission {
            message: Message::ClearString(String::from("Test")),
            security: SecurityClass::Civilian,
            signal_strength: 0,
        };
        assert_eq!(solve_enigma(t, 4242), Err(String::from("Signal lost")));
    }

    #[test]
    fn test_signal_too_weak() {
        let t = Transmission {
            message: Message::ClearString(String::from("Test")),
            security: SecurityClass::Civilian,
            signal_strength: 15,
        };
        assert_eq!(solve_enigma(t, 4242), Err(String::from("Signal too weak")));
    }

    #[test]
    fn test_military_invalid_key() {
        let t = Transmission {
            message: Message::ClearString(String::from("Test")),
            security: SecurityClass::Military,
            signal_strength: 100,
        };
        assert_eq!(solve_enigma(t, 1234), Err(String::from("Security Breach: Invalid Key")));
    }

    #[test]
    fn test_clear_string_bomb() {
        let t = Transmission {
            message: Message::ClearString(String::from("Bomb")),
            security: SecurityClass::Civilian,
            signal_strength: 100,
        };
        assert_eq!(solve_enigma(t, 4242), Err(String::from("Panic: Bomb detected")));
    }

    #[test]
    fn test_digital_code_404() {
        let t = Transmission {
            message: Message::DigitalCode(404),
            security: SecurityClass::Civilian,
            signal_strength: 100,
        };
        assert_eq!(solve_enigma(t, 4242), Ok(String::from("Not Found")));
    }

    #[test]
    fn test_digital_code_200() {
        let t = Transmission {
            message: Message::DigitalCode(200),
            security: SecurityClass::Civilian,
            signal_strength: 100,
        };
        assert_eq!(solve_enigma(t, 4242), Ok(String::from("OK")));
    }

    #[test]
    fn test_encrypted_wrong_key() {
        let t = Transmission {
            message: Message::Encrypted(String::from("Secret"), 1111),
            security: SecurityClass::Civilian,
            signal_strength: 100,
        };
        assert_eq!(solve_enigma(t, 4242), Err(String::from("Encryption Error: Wrong Key")));
    }

    #[test]
    fn test_artificial_noise() {
        let t = Transmission {
            message: Message::ClearString(String::from("123456789")),
            security: SecurityClass::Civilian,
            signal_strength: 100,
        };
        assert_eq!(solve_enigma(t, 4242), Err(String::from("Artificial Noise")));
    }

    #[test]
    fn test_valid_message() {
        let t = Transmission {
            message: Message::ClearString(String::from("Hello World")),
            security: SecurityClass::Civilian,
            signal_strength: 100,
        };
        assert_eq!(solve_enigma(t, 4242), Ok(String::from("Hello World")));
    }
}
