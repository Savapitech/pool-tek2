{-
-- EPITECH PROJECT, 2026
-- Pool-tek2
-- File description:
-- Day03
-}

data Item = Sword | Bow | MagicWand deriving(Eq)

data Mob = Mummy | Skeleton Item | Witch (Maybe Item) deriving(Eq)

instance Show Item where
    show Sword = "sword"
    show Bow = "bow"
    show MagicWand = "magic wand"

createMummy :: Mob
createMummy = Mummy

createArcher :: Mob
createArcher = Skeleton Bow

createKnight :: Mob
createKnight = Skeleton Sword

createWitch :: Mob
createWitch = Witch Nothing

createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

create :: String -> Maybe Mob
create "mummy" = Just createMummy
create "doomed archer" = Just createArcher
create "dead knight" = Just createKnight
create "witch" = Just createWitch
create "sorceress" = Just createSorceress
create _ = Nothing

equip :: Item -> Mob -> Maybe Mob
equip item (Skeleton _) = Just (Skeleton item)
equip item (Witch _) = Just (Witch (Just item))
equip _ Mummy = Nothing

instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton otherItem) = "skeleton holding a " ++ show otherItem
    show (Witch Nothing) = "witch"
    show (Witch (Just MagicWand)) = "sorceress"
    show (Witch (Just otherItem)) = "witch holding a " ++ show otherItem

class HasItem a where
    getItem :: a -> Maybe Item;
    hasItem :: a -> Bool;
    hasItem a = case getItem a of
        Nothing -> False
        (Just _) -> True

instance HasItem Mob where
    getItem Mummy = Nothing
    getItem (Witch (Just item)) = Just item
    getItem (Skeleton item) = Just item
    getItem _ = Nothing
