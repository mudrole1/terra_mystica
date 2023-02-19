# About this project

Terra mystica is a very complex board game (https://www.feuerland-spiele.de/dateien/Terra_Mystica_EN_1.0_.pdf). This project aims to help players by generating all possible actions they can take. 

# Terra mystica rules very briefly

In terra mystica, each player plays as a single 'Faction' and develops its kingdom by building several diferent types of buildings, which cost resources (workers, coins) but also provide income (workers, coins, power, priests). All player share the same map, which is a collection of hexagons, each having different colour (i.e. terrain type). A faction can build only on its colour but there is a way how to change the terrain to different type. terr

There are 8 main types of actions:
 * terraform (change the terrain type) and build a dwelling
 * upgrade shipping distance
 * upgrage cost of spades
 * upgrade a building
 * commit a priest to a cult
 * use power to get an item/ an action from the main board
 * special action (from castle, bonus card, favour tile)
 * pass (end the round for yourself)
 
A player can play only one action from the list above in their turn. However, there are also two actions with power which can be taken additionally to the top ones:
 * convert power to monk/ worker/ coin
 * burn power to upgrade power to third bowl
 
I said, there are 8 types of actions, but there can be many instances of those. Hence, in each turn, the player need to decide between tens of possible actions. Therefore, this project aims to help with the fact that the code will automatically generate a list of all possible actions. This can be useful especially for a novice player. 

# How to compile

I will add CMAKE but for now

```
g++ -g -Wall src/main.cpp src/Tile.cpp src/BoardMap.cpp src/Dwelling.cpp src/Building.cpp src/Action.cpp src/TerraFormAction.cpp src/Faction.cpp src/Game.cpp src/Coordinate.cpp -o game -I include/
```

# Status
19.2.2023: generating terraforming actions and allowing a player to perform the chosen action
