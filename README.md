[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10815667&assignment_repo_type=AssignmentRepo)
# BirbyDB-CS180
BirbyDB is an online database platform  designated to sharing and discovering bird observations from around the state of California, for bird enthusiasts and nature observers of all levels of interest to provide a space for learning, sharing, and exploring the world of birds.

**Team members:**
* Billy Chau (bchau010@ucr.edu)
* Francisco Quiroz-Vivar (fquir007@ucr.edu)
* Caryn Iwanaga (ciwan001@ucr.edu)
* Eddy Tat (etat002@ucr.edu)
* Anjali Daryani (adary001@ucr.edu)

**Choice of interface:** Webpage Interface

**Interface Documentation**
Bird_Record:
- Stores information about birds
- CRUD operations
- Essentially a struct
Collection:
- Stores bird_records
- Linked to users
- Search and sorting functions
- Can be seen by other users
- Can add bird_records from other collections to theirs
Users
- Stores information about users
- Collections are linked by users
- Multi-leveled admin privileges
- Regular_user and Admin_user inherit from this class
Databases
- Class that interacts with the data
- Stores all the data
- Login functionality
- Is used with crow to communicate between frontend and backend

**Programming language(s):** C++, HTML/CSS

**High-level description:**


**Feasibility study:**
It is feasible, but with our current skills, we are entirly learning new technologies and packagesas. We anticipated challenges but are committed to acquiring the necessary skills to successfully implement the platform.

**Initial list of features:**
* Observation Sharing: Allows users to share their bird observations with a community of fellow enthusiasts, fostering knowledge exchange and collaboration.
* Uploading contributions: Empowers users to contribute to the database by uploading their own bird observations, enriching the collective knowledge base.
* Sorting, Viewing, and Editing Collective DB: Users can easily sort, view, and edit bird observations based on various criteria, such as species, location, and time.
* Personalized lists: Enables users to curate personalized lists of observations, facilitating the management of favorite birds and desired sightings.

**Database Documentation:** 
