# Description
Welcome to Sushi Slice Clicker, a fun and addictive cookie clicker clone with a delicious twist! In this simple yet entertaining game, you're not collecting cookies, but scrumptious sushi slices. The goal is straightforward: click on the sushi slices as fast as you can to accumulate points. The more you slice, the higher your score!

# Media
## YouTube (Click)

[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/SW_mv80fHx4/0.jpg)](https://www.youtube.com/watch?v=SW_mv80fHx4)

## Screenshots

![image](https://github.com/forsbergsskola-se/212-cpp-game-KaleSmug/assets/7360266/7545bf46-f62d-4aa2-b63a-09446aa3120b)

![image](https://github.com/forsbergsskola-se/212-cpp-game-KaleSmug/assets/7360266/9bc5daa8-1657-49c6-92d1-80b7b2ba6ea4)


# Key features of the game:

Click on the sushi slice to earn points.
Custom-designed font for the score tracker, adding a unique touch to the game.
Design Patterns and Advanced C++ Features
Observer Pattern
The Observer Pattern is a crucial design pattern used in Sushi Slice Clicker to handle the interaction between the game's components. Here's how it works:

Subject (Score Tracker): The score tracker acts as a subject that maintains a list of observers (listeners) interested in its state changes. In our game, the score tracker keeps track of the player's score.

Observers (Game Elements): The game elements, such as the sushi slices, act as observers. They register with the score tracker as observers to receive updates whenever the player earns points by clicking on them.

Notification: When a player clicks on a sushi slice, the score tracker notifies all registered observers (sushi slices) about the change in the player's score. This enables the game elements to react accordingly, updating their appearance or behavior.

By implementing the Observer Pattern, we ensure a clean separation of concerns between the score tracking logic and the game elements. This promotes modularity and maintainability in our codebase.

# Advanced C++ Features
To create an efficient and well-structured Sushi Slice Clicker, we leveraged various advanced C++ features, including:

Object-Oriented Programming (OOP): We organized our code into classes and objects to encapsulate game elements and their behavior, promoting code reusability and readability.

Smart Pointers: We used smart pointers, such as std::shared_ptr, to manage memory and prevent memory leaks, ensuring a more robust and stable game.

Custom Fonts: We incorporated custom-designed fonts for the score tracker, enhancing the visual appeal of the game. This demonstrates our ability to work with graphical assets and integrate them into our C++ project.



# Build of the Game
You can find the build of Sushi Slice Clicker in the "build" directory of this repository. Simply download the appropriate executable for your platform (Windows, macOS, or Linux) and run the game to start slicing sushi and earning points.

Enjoy playing Sushi Slice Clicker, and have fun sharpening your clicking skills while savoring delicious virtual sushi slices!

