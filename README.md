# 📘 README
## 🌐 Digital Marketing Funnel Management System using BST

---

## 📌 🏷️ Project Title  
Digital Marketing Funnel Management System using Binary Search Tree (BST)

---

## 👥 🤝 Team Members  
- 👤 Jashu  
- 👤 Abhiram 
- 👤 __________  

---

## ❓ 📍 Problem Statement  

In digital marketing, businesses follow multiple stages such as Awareness, Interest, Consideration, and Conversion. Managing these stages manually becomes difficult when the data grows.

The problem is to design a system that can:
- Efficiently store funnel stages  
- Quickly search and update stages  
- Delete unnecessary stages  
- Display the funnel in a structured format  

This project solves the problem using a Binary Search Tree (BST) for efficient data management.

---

## 🌳 📊 Data Structure Used  

Binary Search Tree (BST)

A BST is a tree data structure where:
- Left subtree contains smaller values  
- Right subtree contains larger values  

Advantages:
- Fast searching  
- Efficient insertion and deletion  
- Hierarchical representation  

---

## ⚙️ 🔍 Algorithm Explanation  

1. Node Creation  
- Allocate memory using malloc()  
- Store stage name and description dynamically  

2. Insertion  
- Compare stage names using strcmp()  
- If smaller → go left  
- If larger → go right  
- Insert at correct position  

3. Searching  
- Start from root  
- Compare with target stage  
- Traverse left or right  
- Stop when found or NULL  

4. Update  
- Search the node  
- Replace old description with new description  

5. Deletion  
- No child → delete directly  
- One child → replace with child  
- Two children → replace with inorder successor  

6. Display (Traversal)  
- Uses reverse inorder traversal  
- Displays tree structure  

7. Additional Operations  
- Count total nodes  
- Display leaf nodes  
- Calculate tree depth  

---

## 💻 ⚒️ Compilation Instructions  

Step 1: Save file  
funnel.c  

Step 2: Compile  
gcc funnel.c -o funnel  

Step 3: Run  
./funnel  

---

## 🖥️ 📌 Sample Output  

==== DIGITAL MARKETING FUNNEL MENU ====
1. Create Root Stage
<img width="582" height="333" alt="Screenshot 2026-04-06 232158" src="https://github.com/user-attachments/assets/99a95a98-867a-471c-9969-427cbc1a7bd1" />

2. Add Funnel Stage
  <img width="478" height="319" alt="Screenshot 2026-04-06 232205" src="https://github.com/user-attachments/assets/b4717f63-9359-4bf2-b2d3-3e8496693ea1" />

3. Update Stage
<img width="681" height="348" alt="Screenshot 2026-04-06 232337" src="https://github.com/user-attachments/assets/e9828a55-4d32-4f58-afc7-f5e820d7e76f" />

4. Delete Stage
   <img width="572" height="300" alt="Screenshot 2026-04-06 232409" src="https://github.com/user-attachments/assets/f2c2e8af-b8b8-4b29-99b9-ed91ab8b9113" />

5. Search Stage
   <img width="645" height="325" alt="Screenshot 2026-04-06 232328" src="https://github.com/user-attachments/assets/b53f27ae-4294-4d4c-b9dc-100ca5516fde" />

6. Display Funnel Tree
   <img width="618" height="361" alt="Screenshot 2026-04-06 232255" src="https://github.com/user-attachments/assets/e8fa1e9d-744b-411c-9282-84ce08994962" />

7. Count Stages
   <img width="613" height="305" alt="Screenshot 2026-04-06 232346" src="https://github.com/user-attachments/assets/63ad5820-2a1a-4c25-ba19-0c14b1fa002c" />

8. Show Leaf Stages
   <img width="484" height="319" alt="Screenshot 2026-04-06 232354" src="https://github.com/user-attachments/assets/8f0a50a1-4028-45c0-82da-67a381805631" />

9. Funnel Depth
    <img width="564" height="303" alt="Screenshot 2026-04-06 232401" src="https://github.com/user-attachments/assets/7b89ffbf-15f1-4c1e-b81f-f6294d884f73" />

10. Exit
<img width="630" height="287" alt="Screenshot 2026-04-06 232428" src="https://github.com/user-attachments/assets/89941a3f-2299-4cb0-baf4-aaf4e52e5948" />


---

## 🎯 ✅ Conclusion  

This project demonstrates:
- Use of Binary Search Tree (BST)  
- Dynamic memory allocation  
- Real-world application in marketing  

Future improvements:
- GUI interface  
- File storage  
- Analytics features  

---

## ⭐ 📌 Key Features  
- Fast operations  
- Dynamic data handling  
- Structured display  
- Menu-driven program  
