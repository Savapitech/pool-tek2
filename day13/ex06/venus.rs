use std::fmt;

pub mod life_struct {
    #[derive(Default)]
    pub struct Board {
        pub(super) size_x: i64,
        pub(super) size_y: i64,
        pub(super) board: Vec<char>,
    }

    pub trait GameOfLife {
        fn new(size_x: i64, size_y: i64) -> Self;
        fn next(&mut self);
        fn add_life(&mut self, x: i64, y: i64) -> Result<(), String>;
    }

    impl GameOfLife for Board {
        fn new(size_x: i64, size_y: i64) -> Self {
            Board {
                size_x,
                size_y,
                board: vec!['.'; (size_x * size_y) as usize],
            }
        }

        fn add_life(&mut self, x: i64, y: i64) -> Result<(), String> {
            if x < 0 || x >= self.size_x || y < 0 || y >= self.size_y {
                return Err("Wrong index".to_string());
            }
            
            let index = (y * self.size_x + x) as usize;
            self.board[index] = 'o';
            Ok(())
        }

        fn next(&mut self) {
            let mut new_board = vec!['.'; (self.size_x * self.size_y) as usize];
            
            for y in 0..self.size_y {
                for x in 0..self.size_x {
                    let index = (y * self.size_x + x) as usize;
                    let alive_neighbors = self.count_neighbors(x, y);
                    
                    let is_alive = self.board[index] == 'o';
                    
                    new_board[index] = if is_alive {
                        if alive_neighbors == 2 || alive_neighbors == 3 {
                            'o'
                        } else {
                            '.'
                        }
                    } else {
                        if alive_neighbors == 3 {
                            'o'
                        } else {
                            '.'
                        }
                    };
                }
            }
            
            self.board = new_board;
        }
    }

    impl Board {
        fn count_neighbors(&self, x: i64, y: i64) -> usize {
            let mut count = 0;
            
            for dy in -1..=1 {
                for dx in -1..=1 {
                    if dx == 0 && dy == 0 {
                        continue;
                    }
                    
                    let nx = x + dx;
                    let ny = y + dy;
                    
                    if nx >= 0 && nx < self.size_x && ny >= 0 && ny < self.size_y {
                        let index = (ny * self.size_x + nx) as usize;
                        if self.board[index] == 'o' {
                            count += 1;
                        }
                    }
                }
            }
            
            count
        }
    }
}

pub use self::life_struct::{Board, GameOfLife};

impl fmt::Display for Board {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        for y in 0..self.size_y {
            for x in 0..self.size_x {
                let index = (y * self.size_x + x) as usize;
                write!(f, "{}", self.board[index])?;
            }
            if y < self.size_y - 1 {
                writeln!(f)?;
            }
        }
        Ok(())
    }
}
