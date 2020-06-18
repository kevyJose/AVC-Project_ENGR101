# AVC-Project_ENGR101

AVC Plan

Team Name: KDLC Boys

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
Project Manager (organising team meetings, reporting regularly on progress)

Software Developer (writing core code and extending functionality, testing and documentation, debugging and committing to git, writing test cases and documenting performance against milestones)

* Core - following the line 
* Completion - includes obstacles and dead-ends, 90-deg corners
* Challenge - more of a maze structure...stay between the walls...corridor shape

### DATED PLAN AND MILESTONE GOALS

**- Week Ending 5<sup>th</sup> June 2020**

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
    
**- Week Ending 12<sup>th</sup> June 2020**

Objective for this week: **Core and Completion Code.**  
Tasks to complete this:  
1. - [x] Write the code to allow robot to complete CORE difficulty maze.    
2. - [x] Write the code to allow robot to complete COMPLETION difficulty maze.    
3. - [x] TESTING: Check code completes maze consistently within given time - debug and fix to ensure this occurs.    
4. - [x] Ensure everyone is contributing as expected, following the plan and keeping contact/guiding team to keep within schedule.    
5. - [x] Maintain GitHub repository   
         - Including updating plan/README, updating Wiki and maintaining files. 
         
*Possible Functions to be called per frame capture:  
1.   *Kevin - Check if white line is present in frame (scan white pixels).  
     >>Calculate the location of white pixels of the line  
     >>Has a buffer (allows 250) for white line color if not exactly white (255,255,255).  
2.   *Christian - Check if the white line is in the middle of the frame.  
     >>Find the current position of the middle white pixel Calculate for the white line being in the middle of the frame.
     >>Then make calculations to compare the middle pixel position to the centre of the array.     
3.   *Daniel - Change the direction of robot (move a little left or right) if white pix. not in the middle of the frame.  
     >>Adjust the speed of motors respectively.
     >>maintain white line in centre of frame
4.   *Lee - Reverse the robot if the line is not present until line is found again.  
     >>Adjust the speed in a negative direction.    
       
Challenges / conflicts of this week:
- Assignments for COMP102/112 , ENGR121 and CYBR171 may reduce time commited to AVC project, possibly impeding progress
- Making the functions work together...smart collaboration/communication NEEDED! 
- Kevin faced some issues when running/testing the program...but eventually sorted it out by end of week 
       
Due this week:   
    - Project progress check (Wiki discussion etc)  
    - Core code should be done (At the very least...if completion or further work is possible) by the end of this week.
    
    
               

**- Week Ending 19<sup>th</sup> June 2020**  

Objective for this week: **Challenge Code - Coding part of project complete**  
Tasks to complete this:
1. [x] Ensure everyone contributes as expected within team environment, plan is followed within schedule. 
2. [ ] Write the code to allow robot to complete challenge difficulty maze. 
3. [x] Iterative TESTING: Make checkpoints and keep testing code as devleopment is made. Ensure that current code is functioning as it should. Do the necessary debugging and fixes as it is needed. 
4. [ ] Clean up all of written code to ensure it complies with given restrictions and is more accessible and readable. Add more functions and make more modular if necessary.
5. [ ] FULL-PROGRAM TESTING: Do a full/overall test of the program...this might happen on FINAL day of development. Make sure all functions and capabilities are working as intended. Check this code completes the course consistently within given time - make any minor tweaks and fixes where it's needed.
7. [ ] Final check/read-through of code to be submitted, carefully checking to ensure all works as intended before submission date.
8. [x] Maintain GitHub repository.   
       - Including updating plan/README, updating Wiki, adding branches to MASTER code and maintaining files.
9. [ ] Submit final code.  
10. [ ] Ensure everyone is on track for remainder of project 3 (Logs and reports)  

Challenges / conflicts of this week:  
    - ENGR121 test and COMP102/112 assignments to complete as well - will be a big draw of time from team members that will impact on time working on AVC project.  

Due this week:  
    - Code of project (All of core, completion and challenge) to be submitted on 19<sup>th</sup> June.  
