# Endless Runner - Udit Shroff

### The Ground
I have used a Scrolling Texture Shader for my Ground whose speed I can control with my GameMode Object at runtime.

### The Player
The Players are setup to run at a single position while the ground scrolls below them and the obstacles slide towards them, they can dodge these obstacles by switching lanes. To achieve local multiplayer another set of Capsule component and Skeletal Mesh Components were added to the Default Player Actor. There are inputs setup on A and D (Player 1) and Left and Right Arrow Keys (Player 2) to switch to their respective left and right lanes.

### ObstacleManager
The Obstacle Manager is a UObject Class that handles the creation and recycling of the Obstacle Meshes during the gameplay. It now also handles the disappearing of further obstacles as a reward of dodging obstacles that just passed the player. We can set how often we want it to happen as a default in the child BPClass;

### Obstacle Component
The Obstacle Component is created on BeginPlay as Sub Objects for the Obstacle Manager. They are responsible for moving the Obstacle Meshes towards the player according to the current speed specified in the game mode class & notifying the obstacle manager when they are ready to be recycled as a new obstacle.

### Obstacle Data
A Dataset Class holding the Mesh and Transform Data for different Obstacle types, an array of these is supplied to the Obstacle Manager to choose from when creating or recycling Obstacles.

### Obstacle Recycler
A trigger volume child object setup behind the player just off the camera, in charge of triggering the recycling process when obstacles overlap with its trigger area.

### Obstacle Disappear
A trigger that works similar to the Recycler but is placed further down the road. The manager keeps a track of how many obstacles are to be removed temporarily before recycling them and this trigger removes colliding obstacles if that number is more than 0.

### ScoreBoard
This is a class derived from USaveGame which is being used to save the current recorded highscore in that local system and overwrite it if broken.
