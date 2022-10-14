# cs311TFTbuilder
A very messy but kind of working TFT builder from set 3, my favorite set. 

1.	Which data structure did you use?
a.	I used the hash table  

2.	What is your element object? Describe its >= 4 parts and draw an example with example values. 
a.	My element object uses 4 parts it has a Name, Class, Origin, and Cost




3.	  Field	         		type          	 example value
4.		ChampionName	    String		        Lux
5.		ChampionClass	    String		        Sorcerer
6.		ChampionOrigin    String		        Dark Stars
7.		ChampionCost  	 	Int		            3
a.	
1.	Why is your program useful? What can you do with it?

Describe search using what key?  Sort using what key?  

My program is useful since it allows someone to search up based on champion name and get what class, origin, and cost the champion is. I search by using the name.

2.	In what format the input data is stored in a file? Describe using an example line from the file.
Write back updated data to which file? Give the name.  
The input data is stored in a String, String, String, Int format, so a Name, Class, Origin and then the cost and the updated file is written to a file called championRoster.txt.
 
3.	List all new member functions/operator overloading. To which class? What are their names? For what purpose?  If a hash table, what does the new hash function do?  Explain using an example.
All new member functions are deleteItem, addAChampion, findSlotNumber, inputFile, and outputFile. These are all written in the htable.cpp file and the purpose of delteItem is to delete something from the database, addAChampion, adds a champion to the database, findSlotNumber is used to find the slot number in the hash table of any champion, inputFile and outputFile are both used to read and write to files into and out of the database. The new hash function takes a string and converts each letter in the string to its ascii value and then adds them all up until moduloing it by the TSIZE. For example the name VI when converted to ASCII has the value 86 + 73, which is equal to 159. It is then moduloed by TSIZE so 159 % TSIZE (which is 61) so it ends up being in slot number 159 % 61 = 37. slot 37.

4.	Explain the chosen size if a static structure (HW4 and HW8)
(e.g. for a hash table, consider the load factor and using the prime number)

I chose 61 since there are 51 champions in total for the data file and has about an 83% load factor which is perfect for a hash table. 
