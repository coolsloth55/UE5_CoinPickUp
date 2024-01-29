# UE5_CoinPickUp

## Coin

* Added pawn which checks if object is `ACharacter` on overlap. 

## HUD

* Created blueprint for HUD.
* Created blueprint for widget.
    * Added canvas and text block called `Score` to match widget class.
* Added widget class on HUD blueprint.

## Game Mode

* Created blueprint of type `ACoinPickUpGameMode`.
* Set default game mode of world to newely created blueprint not directly to `CoinPickUpGameMode`.