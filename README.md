# Installation MANUAL for Windows 10 (mingW and Geany)

NOTE: you should already have MingW installed before you begin the following STEPS:

**INSTALLING:**
- go to SFML website: www.sfml-dev.org/download/sfml/2.5.1/

- download the "MinGW Builds 7.3.0" and "GCC 7.3.0 MinGW (SEH)" files from the above website. Choose 32bit or 64bit version files, depending on your PC
		
- download the 'AVC_Win10.zip' folder from attachments on the ENGR101 project website

- extract the "GCC 7.3.0 MinGW (SEH)" Zip folder to the root of C drive. Rename the extracted folder to 'SFML'

- extract the 'AVC_Win10' folder into the folder where your project is stored

- open up the 'robot.cpp' file which is in the 'AVC_Win10" folder, with Geany

- Once you have the cpp file in geany, click the drop-down menu next to the 'build' button, then click 'set build commands'.

- A small window will open up...so then change the 'Independent commands' by adding "mingw32-" to the front of the three fields.
 
- then click "OK"!


**TESTING ROBOT PROGRAM:**
- open up the "sever.exe" application, leave the console windows open!

- then return back to the robot.cpp file in Geany. Click the build drop-down...then click "Make all". Wait for the message "compilation finished successfully"

- then click "execute"

- in the server console...you should see the robot begin moving.

- If robot moves after execution...then SETUP is successful


**TROUBLESHOOTING (try following STEPS if SETUP unsuccessful):**
- go to the "AVC_robot" folder and open up the "makefile" document. In lines 4 and 6...remove the indenting and then press "Tab" for each line

- check your current environment variables

- check that your 'MingW' program and 'SFML' folder are matching. Are they both 32bit or are they both 64bit?

- Make sure you have the latest build of MingW (version 7.3.0)


# AVC Project Plan (ENGR101)
### Team Name: KDLC Boys

Team Members & contact info:  
Kevin Jose (josekevi@myvuw.ac.nz)  
Daniel Cross (crossdani@myvuw.ac.nz)  
Lee Scanlon (scanlolee@myvuw.ac.nz)  
Christian Struwig (struwichri@myvuw.ac.nz)  

Communication tool: Facebook Messenger, Zoom  

Roles:\
Project Manager/Developer - Kevin  
Software Developer - Daniel  
Software Developer - Lee  
Software Developer - Christian

Role Descriptions:
* **Project Manager** (organising team meetings, reporting regularly on progress)
* **Software Developer** (writing core code and extending functionality, testing and documentation, debugging and committing to git, writing test cases and documenting performance against milestones)

Development Stages:
* **Core** - following the line 
* **Completion** - includes obstacles and dead-ends, 90-deg corners
* **Challenge** - more of a maze structure...stay between the walls...corridor shape

---------------------------------------------------------------------------------------------------------------------------------
### DATED PLAN AND MILESTONE GOALS

## **Week 1 (Ending 5<sup>th</sup> June 2020)**

Objective for this week: **Start the project**  
Tasks to complete this:
1. - [x] Make contact with the team. 
2. - [x] Ensure everyone's installations are corrrect.
       - [x] Check to make sure everyone will have capability to work on project.
       - [x] Ensure SFML is installed for everyone.
       - [x] Test all installations work and everyone's machines can run server3.cpp and robot.cpp correctly.
3. - [x] Complete plan and goals for team to adhere by through project.
4. - [x] Assign roles and tasks for team members to complete.
5. - [x] Oragnise team meetings (to be continued throughout project) for extra discussion of project direction, issues or any other point to be raised regarding progress.    
6. - [x] Begin individual time management logs.  

Challenges / conflicts of this week:
- SFML issues causing problems with getting ready for project.
- Lee facing issues with his setup/installation; waiting on him to FINISH. 
   
Due this week:   
    - AVC project plan.
    
---------------------------------------------------------------------------------------------------------------------------    
## **Week 2 (Ending 12<sup>th</sup> June 2020)**

Objective for this week: **Core and Completion Code.**  
Tasks to complete this:  
1. - [x] Write the code to allow robot to complete CORE difficulty maze.    
2. - [x] Write the code to allow robot to complete COMPLETION difficulty maze.    
3. - [x] TESTING: Check code completes maze consistently within given time - debug and fix to ensure this occurs.    
4. - [x] Ensure everyone is contributing as expected, following the plan and keeping contact/guiding team to keep within schedule.    
5. - [x] Maintain GitHub repository   
         - Including updating plan/README, updating Wiki and maintaining files. 
       
Challenges / conflicts of this week:
- Assignments for COMP102/112 , ENGR121 and CYBR171 may reduce time commited to AVC project, possibly impeding progress
- Making the functions work together...smart collaboration/communication NEEDED! 
- Kevin faced some issues when running/testing the program...but eventually sorted it out by end of week 
       
Due this week:   
    - Project progress check (Wiki discussion etc)  
    - Core code should be done (At the very least...if completion or further work is possible) by the end of this week.
    
--------------------------------------------------------------------------------------------------------------------------------
## **Week 3 (Ending 19<sup>th</sup> June 2020)**  

Objective for this week: **Challenge Code - Coding part of project complete**  
Tasks to complete this:
1. - [x] Ensure everyone contributes as expected within team environment, plan is followed within schedule. 
2. - [x] Write the code to allow robot to complete challenge difficulty maze. 
3. - [x] Iterative TESTING: Make checkpoints and keep testing code as devleopment is made. Ensure that current code is functioning as it should. Do the necessary debugging and fixes as it is needed. 
4. - [ ] Clean up all of written code to ensure it complies with given restrictions and is more accessible and readable. Add more functions and make more modular if necessary.
5. - [ ] FULL-PROGRAM TESTING: Do a full/overall test of the program...this might happen on FINAL day of development. Make sure all functions and capabilities are working as intended. Check this code completes the course consistently within given time - make any minor tweaks and fixes where it's needed.
7. - [ ] Final check/read-through of code to be submitted, carefully checking to ensure all works as intended before submission date.
8. - [x] Maintain GitHub repository.
       - Including updating plan/README, updating Wiki, adding branches to MASTER code and maintaining files.
9. - [ ] Submit final code.  
10. - [ ] Ensure everyone is on track for remainder of project 3 (Logs and reports)
11. - [ ] Add in the Installation Manual into the README.md 

Challenges / conflicts of this week:  
    - ENGR121 test and COMP102/112 assignments to complete as well - will be a big draw of time from team members that will impact on time working on AVC project.  

Due this week:  
    - Code of project (All of core, completion and challenge) to be submitted on 19<sup>th</sup> June.  

----------------------------------------------------------------------------------------------------------------------------------

## **Week 4 (Ending 24th<sup>th</sup> June 2020)**

### Individual Work from HERE....
 - Update and clean up individual logs, make presentable
 - Write brief (1 page) manual for new contractors of the company: How to manage your time
 - Write a comprehensive report...about this software which we developed (max. 10 pgs)

