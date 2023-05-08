# Endless Runner - Udit Shroff

### The Ground
I have used a Scrolling Texture Shader for my Ground whose speed I can control with my GameMode Object at runtime.

### The Player
The Player is setup to run at a single position while the ground scrolls below them and the obstacles slide towards them, they can dodge these obstacles by switching lanes. There are inputs setup on A and D to switch to the left and right lanes.

### ObstacleManager
The Obstacle Manager is a UObject Class that handles the creation and recycling of the Obstacle Meshes during the gameplay.

### Obstacle Component
The Obstacle Component is created on BeginPlay as Sub Objects for the Obstacle Manager. They are responsible for moving the Obstacle Meshes towards the player according to the current speed specified in the game mode class & notifying the obstacle manager when they are ready to be recycled as a new obstacle.

### Obstacle Data
A Dataset Class holding the Mesh and Transform Data for different Obstacle types, an array of these is supplied to the Obstacle Manager to choose from when creating or recycling Obstacles.

### Obstacle Recycler
A trigger volume child object setup behind the player just off the camera, in charge of triggering the recycling process when obstacles overlap with its trigger area.
