# Process to create a new lecture

Please follow the next steps:

0. Plan each lecture's topics according to CPCFI's Syllabus using **Lecture Planner Template** table. This table should be at the Unit Root Directory
1. Within the unit directory, create a new directory with the following template name: ```Lecture-#-New-Lecture-Name```
   1. ```#```: corresponds to the new lecture number
   2. ```New-Lecture-Name```: use hyphens (-) if the lecture name contains whitespaces
   3. For example, [Unit 6](https://github.com/CPCFI-org/lectures/tree/main/6-Graphs-I)'s lecture 1 root directory is named as following: ```Lecture-1-Graph-Traversal-I```
2. Within the unit directory's README file in the **Lectures** table, add a new row with the following information per lecture:
   1. ```Number```: number of the lecture
   2. ```Lecture```: name of the lecture. This attribute should have an hyperlink to the lecture it makes reference
   3. ```Topics```: list the topic names for each lecture (if possible, make them match with the numeration inside [CPCFI's Syllabus](https://github.com/CPCFI-org/lectures/blob/main/CPCFI_Syllabus.pdf))
3. Within the new directory created in **Step 1** (Lecture Directory):
   1. Create a README.md file where the heading (H1) should be the name of the lecture written in the Unit Directory's README file (```Lecture``` attribute)
   2. This README.md file will contain a list of problems per unit's topic. Use the template in the section **Problems Table Template** to create the new markdown table. Add a new entry to this table everytime a relevant problem is solved for the corresponding topic
   3. Create a new directory for each topic
      1. Template: ```#-Name-of-Topic```
         1. ```#```: number of topic within the lecture
         2. ```Name-of-Topic```: use hypens (-) if the topic name contains whitespaces
         3. Example: ```1-BFS``` or ```5-Topological-Sort```

   4. The PDF of the lecture should have the following format: ```unit.# Lecture # - lecture name.pdf```
      1. ```unit```: number of unit the lecture belongs to (1,2,...10)
      2. ```#```: lecture's number within the Unit (1,2,...,6) although a Unit could potentially have less than or greater than 6 lectures
      3. ```lecture name```: lecture's name 
      4. For example: ```6.1 Lecture 1 - Graph Traversal I.pdf```
      5. This PDF should use the white header used in every PDF ([check out this PDF example for the white header](https://github.com/CPCFI-org/lectures/blob/main/6-Graphs-I/Lecture-1-Graph-Traversal-I/6.1%20Lecture%20-%20Graph%20Traversal%20I.pdf))

---

## Lecture Planner Template

| Number | Lecture | Topics |
| ------ | ------- | ------ |
| Number of session (3 weeks per unit) | Name according to CPCFI's Syllabus with link to the Github repository root directory | List according to the syllabus |

**Example**:

| Number | Lecture | Topics |
| ------ | ------- | ------ |
| 1  | [Graph Traversal I](https://github.com/CPCFI-org/lectures/tree/main/6-Graphs-I/Lecture-1-Graph-Traversal-I)  | 6.1.1 DFS, 6.1.2 BFS, 6.1.3 Connected Components, 6.1.4 Coloring Connected Components, 6.1.5 Topological Sort (Antecedents: checking for acyclicity), 6.1.6 Bipartite Graph Check, Extra: Kuhn's Algorithm for Maximum Bipartite Matching |



## Problems Table Template

| Problem | Editorial | Section | 
| ------- | --------- | ------- |
| Link to the problem | Link to editorial (code or text) | Section within the unit's topics this problem belongs to |


**Example**:
| Problem | Editorial | Section |
| ------- | --------- | ------ |
| [CSES Counting Rooms](https://cses.fi/problemset/task/1192/)  | [C++](https://github.com/nestorivanmo/icpc/tree/main/cses/4-Graphs/counting-rooms) | 6.1.1 BFS |
|  [CSES Message Route](https://cses.fi/problemset/task/1667/) | [C++](https://github.com/nestorivanmo/icpc/tree/main/cses/4-Graphs/message-route)  | 6.1.1 BFS |
