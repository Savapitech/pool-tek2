pub struct Storage<T> {
    pub item: T,
}

impl<T> Storage<T> {
    pub fn new(item: T) -> Storage<T> {
        Storage { item }
    }

    pub fn extract(self) -> T {
        self.item
    }
}
