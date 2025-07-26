{-
-- EPITECH PROJECT, 2025
-- B-PDG-300-NAN-3-1-PDGD03-albane.merian
-- File description:
-- Game
-}

data Item = Sword | Bow | MagicWand
    deriving (Eq)

instance Show Item where
    show Sword = "sword"
    show Bow = "bow"
    show MagicWand = "magic wand"

data Mob 
    = Mummy 
    | Skeleton (Item)
    | Witch (Maybe Item)
    deriving (Eq)

instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton item) = "skeleton holding a " ++ show item
    show (Witch Nothing) = "witch"
    show (Witch (Just MagicWand)) = "sorceress"
    show (Witch (Just item)) = "witch holding a " ++ show item

class HasItem a where
    getItem :: a -> Maybe Item
    hasItem :: a -> Bool
    hasItem a = case getItem a of
        Nothing -> False
        Just _ -> True

instance HasItem Mob where
    getItem Mummy = Nothing
    getItem (Skeleton al) = (Just al)
    getItem (Witch Nothing) = Nothing
    getItem (Witch (Just al)) = (Just al)

createMummy :: Mob
createMummy = Mummy

createArcher :: Mob
createArcher = Skeleton Bow

createKnight :: Mob
createKnight = Skeleton Sword

createWitch :: Mob
createWitch = Witch (Nothing)

createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

createWitchSword :: Mob
createWitchSword = Witch (Just Sword)

createWitchBow :: Mob
createWitchBow = Witch (Just Bow)

createSkelWand :: Mob
createSkelWand = Skeleton MagicWand

create :: String -> Maybe Mob
create [] = Nothing
create "mummy" = Just createMummy
create "doomed archer" = Just createArcher
create "dead knight" = Just createKnight
create "witch" = Just createWitch
create "sorceress" = Just createSorceress
create _ = Nothing

equip :: Item -> Mob -> Maybe Mob
equip _ (Mummy) = Nothing
equip Bow (Skeleton _) = Just createArcher
equip Sword (Skeleton _) = Just createKnight
equip MagicWand (Skeleton _) = Just createSkelWand
equip MagicWand (Witch _) = Just createSorceress
equip Sword (Witch _) = Just createWitchSword
equip Bow (Witch _) = Just createWitchBow

