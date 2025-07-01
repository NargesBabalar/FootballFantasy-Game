# Fantasy Premier League Simulator

A complete C++ implementation of a fantasy football simulator based on the Premier League. This system enables users to form and manage their own fantasy squads, simulate weekly fixtures, and calculate scores dynamically using real match data.

---

## 🏟️ Overview

This application replicates the core mechanics of a Fantasy Premier League game:

- Users build custom teams.
- Real-life matches are simulated weekly.
- Player statistics influence fantasy points.
- All data is sourced from CSV files representing real team and player performances.

---

## 🎯 Key Capabilities

- 🎮 **Interactive Admin Console**: Set up leagues, assign fixtures, and process weekly updates.
- ⚽ **Real Match Simulation**: Recreates real team match results week by week.
- 🧠 **User Fantasy Squad Management**: Transfer players, update lineups, and track scores.
- 📊 **Statistical Engine**: Tracks injuries, bookings, and goals with point-based logic.
- 📁 **Data Input via CSV**: Easy data ingestion for both fixtures and player stats.
- 🔁 **Progressive Matchweeks**: Advances simulation across multiple weeks.

---

## 📁 Source File Breakdown

| File            | Purpose                                                                 |
|------------------|--------------------------------------------------------------------------|
| `main.cpp`       | Launches the program and initiates simulation flow.                     |
| `Admin.cpp`      | Provides tools for the admin: managing schedules, teams, and results.   |
| `Futball.cpp`    | Central hub for the game simulation and CSV integration.                |
| `Real_Team.cpp`  | Tracks real club stats: injuries, cards, wins, goals.                   |
| `User_Team.cpp`  | Enables user team editing, transfer logic, and point calculation.       |
| `Player.cpp`     | Represents each player’s state: form, goals, injuries, cards.           |
| `Week.cpp`       | Logs all weekly outcomes and results.                                   |
| `game.cpp`       | Runs the actual match logic between two real teams.                     |

---
