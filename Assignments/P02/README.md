## P02.1
### Kyler Wyatt
### Description:

UML markup for Program 2.

## Classes

### Class Card

#### Description
> Represents Values for a card.

#### Data
- Rank
- Value

#### Methods
- SetRank
- SetValue
- GetRank
- GetValue
- Print

### Class Deck

#### Description
> A container of cards.

#### Data
- Size - How many cards in a deck.
- Remaining - How many cards left.

#### Methods
- Deal - Remove a card from the deck.
- Shuffle - Re-Arrange cards.
- Reset - Go back to initial state of deck.

### Class Hand

#### Description
> A container of cards.

#### Data
- Size - How many cards in a deck.
- Remaining - How many cards left.

#### Methods
- Shuffle - Re-Arrange cards.
- Sort - Put cards in some order.
- Discard - Remove a card intentionally.

### Class Player

#### Description
> Class to represent a player

#### Data
- Bank - How much money the player has.
- Name - An idientifier for the player.
- Hand - Instance of a Hand class.

#### Methods
- Bet - Remove money from the bank.
- Win - Add money to bank.
- Hit - Add a card to hand.

### Class Dealer

#### Description
> Class to represent the dealer

#### Data
- Bank - How much money the player has.
- Name - An idientifier for the player.
- Hand - Instance of a Hand class.

#### Methods
- Bet - Remove money from the bank.
- Win - Add money to bank.
- Hit - Add a card to hand.
- Deal - When the dealer deals cards.

### Class Game

#### Description
> In charge of running the game.

#### Data
- Players - Vector of player classes.
- Dealer - Uses the dealer class.

#### Methods
- Print - Prints games current state.
- AcceptBets - Gathers the bets, only doing $100 right now.
- StartRound - Begins a round.

## UML Diagram

- None for now.
