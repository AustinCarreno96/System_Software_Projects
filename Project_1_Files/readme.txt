Description:
	Project 1 will take in a file as input then convert each row into a student structure. The program will then store a pointer to that structure in an array. I also created a small hashing function to create a key so that each structure is stored at the index of that key, making the array a hash table. While inserting the structure into the hash table my program will look for inconsistencies and not allow structures with said inconsistencies into the hash table. After creating the key, the program will check for duplicates and verify if the element in the table is NULL or if there is already an item's pointer stored there. Once all testing of the structure is finished and the pointer has been stored, the hash table log will print a success message. If the structure was not stored for any reason the program will print the error and why it wasn't stored in the log. Once insertion is complete, the program will then print the table with its contents and quit.

Extra Credit: 
	I have attempted the extra credit but did not complete it. (The code is commented out.)

Experience:
	For this project I had to relearn C. It's been over a year since I touched C and after getting comfortable with languages such as Python, TypeScript, Java, etc. I had to relearn the intricacies of C. That was my biggest challenge here. Everything else seemed pretty straight forward, but remembering malloc and pointers gave me issues in the beginning.

Shortcomings:
	No shortcomings exist

Improvements:
	I might have liked to improve how I test the student data. Writing a lot of if statements is not my favorite way to handle this, but it works and I felt a bit lazy about reworking it. I believe creating a more complex hash function would be the next thing on my list to improve this program. With the next project using parts of this code, I want to create a more creative hash function for it. 