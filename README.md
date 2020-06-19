# Installation MANUAL for Windows 10 (mingW and Geany)  


NOTE: ideally you should already have MingW and Geany installed before you begin the following STEPS:  
If you do not have MinGW installed follow the steps entitled **Getting MinGW:**, otherwise follow **Updating MinGW:** where there are instrictions for updating your currently installed version of MinGW to the correct corresponding version for the SFML build used.   
If you do not have Geany installed download and follow the steps from https://www.geany.org/

**Getting MinGW:**  

- Follow the link to the download page on the SFML website: www.sfml-dev.org/download/sfml/2.5.1/  

- Download the corresponding version of "MinGW Builds 7.3.0" as what will be your chosen SFML install. For this program it is highly recommended (and assumed) that you will insall "MinGW Builds 7.3.0 (64-bit)" - This is the version that is verified to work correctly and should be used with "GCC 7.3.0 MinGW (SEH) - 64-bit" . Do not mix and match these versions - you should use this specific pair.

- Create a folder in your C drive entitled "MinGW" - the directory should be C:\MinGW  

- Extract (Ideally using 7Zip or a similar program) the file downloaded through selecting "GCC 7.3.0 MinGW (SEH) - 64-bit" wherever downloaded. This will result in a folder named "mingw64" being created. The files within this folder should then be moved into the C:\MinGW folder - There should be no intermediary folders meaning that opening the MinGW folder in the C drive will lead directly to the folder containing files "bin" and "lib" for example. To ensure that this is correct the directory within the bin folder should be C:\MinGW\bin if following along exactly    

- Press your windows button (or just open windows search) and type in / search for environment variables - click on and open the option "Edit the system environment variables"  

- From there select the "Environment Variables..." button then select the variable entitled "Path" and press the "Edit" button underneath the box entitled "User variables for \[your username here\]"  

- Press "New" and paste in the directory to the "bin" folder in the MinGW C drive folder - It should be along the lines of C:\MinGW\bin if installed in the directed place. To get this yourself open the bin folder and click into the file path that shows the current folder and then copy/paste when selected "New"  

- Restart your PC to ensure changes are applied and move onto the installation step. (It may be a good idea to check that the compiler is working correctly by attempting to compile, build and run a sample file (perhaps a simple hello world program))  

**Updating MinGW:**  

- Follow the link to the download page on the SFML website: www.sfml-dev.org/download/sfml/2.5.1/  

- Download the corresponding version of "MinGW Builds 7.3.0" as what will be your chosen SFML install. For this program it is highly recommended (and assumed) that you will insall "MinGW Builds 7.3.0 (64-bit)" - This is the version that is verified to work correctly and should be used with "GCC 7.3.0 MinGW (SEH) - 64-bit" . Do not mix and match these versions - you should use this specific pair.  

- Extract the file downloaded through selecting (using 7Zip or similar) "MinGW Builds 7.3.0 (64-bit)", replace the contents of your C:\MinGW folder with everything in this new folder. *If you do not have this folder in your C drive follow **Getting MinGW** instead* - The contents of this install should replace everything in the currently existing folder so you should delete all current contents and then move the new contents inside the extracted "mingw64" folder into C:\MinGW  

- This should update your install of MinGW (if it has been set up correctly before with changing environment variables)  

**INSTALLING:**  
Before being able to run robot.cpp and have the robot complete the maze you must first install the correct versions of the minGW c++ compiler and the corresponding SFML build.  

- Follow this link to the download page on the SFML website: www.sfml-dev.org/download/sfml/2.5.1/  

- Download the "MinGW Builds 7.3.0" and "GCC 7.3.0 MinGW (SEH)" files from the above website. Choose 32bit or 64bit version files, depending on your PC. Make sure these versions selected match and we highly recomment the 64 bit option. If you are to follow this manual as intended install "MinGW Builds 7.3.0 (64-bit)" and "GCC 7.3.0 MinGW (SEH) - 64-bit"
  - ***follow the instuctions around getting or updating MinGW to correctly configure your MinGW install***  

- Extract the "GCC 7.3.0 MinGW (SEH)" Zip folder to your C drive. Rename the extracted folder to 'SFML' - This should provide you with a directory location of C:\SFML - Ensure that the folders and files of the SFML build (i.e. bin, doc) are within C:\SFML and not nested in another folder (i.e. ensure directory to bin folder is C:\SFML\bin)  

- Download the "AVC_Win10_KDLCBoys.zip" folder from this repository if you haven't got it already  

- Extract the 'AVC_Win10_KDLCBoys.zip' folder to the destination you would like it to be stored  

- Go to C:\SFML\bin and copy all the .dll files (There will be 11) in this folder  

- Paste these files into the "AVC_robot" and "AVC_server" folders - selecting replace current files in destination folder to ensure the .dll files match  

- Open up the 'robot.cpp' file which is in the 'AVC_robot" folder, with Geany (This should be the correct updated version, however it may be a good idea to copy the code from opening "robot.cpp" from the GitHub repository directly and copy in this code to robot.cpp, save then carry on)  

- Once you have the cpp file in geany, click the drop-down menu next to the 'build' button, then click 'set build commands'.

- A small window will open up...so then change the 'Independent commands' by adding "mingw32-" to the front of the three fields which should result in "mingw32-make" for Independant commands 1 and 2, and "mingw32-make %e.o" for command 3.
 
- then click "OK"!

- Open the "makefile" in both "AVC_robot" and "AVC_server" folders with Geany. ensure that the spacing in line 6 and 8 are tabbed indented. To do this remove the space on these lines and then readd it by pressing your TAB key **ONCE** - It would also be ideal to check that the directory on line 1 is correct - meaning that the line "DIR = C:\\SFML" should be pointing to where your SFML folder is on your C drive.  


**TESTING ROBOT PROGRAM:**
- Open "server3.cpp" from the AVC_server folder with geany then click "Compile". Once this is done press "Make all" from the drop down menu next to "Build" and then once this is complete press "Execute" to run the server (Alternatively select server3.exe from the AVC_server folder when "Make all" completes.) Leave the console open.

- Return back to the robot.cpp file in Geany. Click the build drop-down...then click "Make all". Wait for the message "compilation finished successfully"

- Then click "Execute"

- Select which map type is being tried by entering "1" for Core and Completion or "2" for Challenge in the server console. The robot should then begin moving.

- If robot moves after execution...then SETUP is successful

- To change the map being tested open "config.txt" in the AVC_server folder and change where it says "challenge.txt" after the comma to be "core.txt" for the Core map, "completion.txt" for the Completion map or "challenge.txt" for the Challenge map.

**TROUBLESHOOTING (try following STEPS if SETUP unsuccessful):**
- go to the "AVC_robot" folder and open up the "makefile" document. In lines 6 and 8...remove the indenting and then press "Tab" for each line

- check your current environment variables are correct - follow this process in **Getting MinGW**  

- check that your 'MingW' program and 'SFML' folder are matching. Are they both 32bit or are they both 64bit?

- Make sure you have the correct build of MingW for the SFML build we are using (MinGW version 7.3.0) 
<br />


# AVC Project Plan
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
4. - [x] Clean up all of written code to ensure it complies with given restrictions and is more accessible and readable. Add more functions and make more modular if necessary.
5. - [x] FULL-PROGRAM TESTING: Do a full/overall test of the program...this might happen on FINAL day of development. Make sure all functions and capabilities are working as intended. Check this code completes the course consistently within given time - make any minor tweaks and fixes where it's needed.
7. - [x] Final check/read-through of code to be submitted, carefully checking to ensure all works as intended before submission date.
8. - [x] Maintain GitHub repository.
       - Including updating plan/README, updating Wiki, adding branches to MASTER code and maintaining files.
9. - [x] Submit final code.  
10. - [x] Ensure everyone is on track for remainder of project 3 (Logs and reports)
11. - [x] Add in the Installation Manual into the README.md 

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

