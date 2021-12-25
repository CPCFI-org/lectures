# Process to create a new lecture

Please follow the next steps:

1. Within the unit directory, create a new directory with the following template name: ```Lecture-#-New-Lecture-Name```
   1. ```#```: corresponds to the new lecture number
   2. ```New-Lecture-Name```: use hyphens (-) if the lecture name contains whitespaces
   3. For example, [Unit 6](https://github.com/CPCFI-org/lectures/tree/main/6-Graphs-I)'s lecture 1 root directory is named as following: ```Lecture-1-Graph-Traversal-I```
2. Within the unit directory's README file, add a new row with the following information per lecture:
   1. ```Number```: number of the lecture
   2. ```Lecture```: name of the lecture
   3. ```Topics```: list the topic names for each lecture (if possible, make them match with the numeration inside [CPCFI's Syllabus](https://github.com/CPCFI-org/lectures/blob/main/CPCFI_Syllabus.pdf))
3. Within the new directory created in **Step 1** (Lecture Directory):
   1. Create a README.md file where the heading (H1) should be the name of the lecture written in the Unit Directory's README file (```Lecture``` attribute)
   2. This README.md file will contain a list of problems per unit's topic. Use the template in the section **Problems Table Template** to create the new markdown table. Add a new entry to this table everytime a relevant problem is solved for the corresponding topic
   3. Finally, create a new directory for each topic
      1. Template: ```#-Name-of-Topic```
         1. ```#```: number of topic within the lecture
         2. ```Name-of-Topic```: use hypens (-) if the topic name contains whitespaces
         3. Example: ```1-BFS``` or ```5-Topological-Sort```


## Problems Table Template

| Problem | Editorial | Section | 
| ------- | --------- | ------- |
| Link to the problem | Link to editorial (code or text) | Section within the unit's topics this problem belongs to |


**Example**:
| Problem | Editorial | Section |
| ------- | --------- | ------ |
| [CSES Counting Rooms](https://cses.fi/problemset/task/1192/)  | [C++](https://github.com/nestorivanmo/icpc/tree/main/cses/4-Graphs/counting-rooms) | 6.1.1 BFS |
|  [CSES Message Route](https://cses.fi/problemset/task/1667/) | [C++](https://github.com/nestorivanmo/icpc/tree/main/cses/4-Graphs/message-route)  | 6.1.1 BFS |
