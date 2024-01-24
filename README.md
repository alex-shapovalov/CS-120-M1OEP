Alex Shapovalov
1/24/2023 (Start Date)
M1OEP

The purpose of this project is to create a complex calendar tool within the Gregorian Calendar. The program is going to take in a specified date between 01/01/0001 and 12/31/9999 and print out the day of the week of that date, the entire calendar for that month, and any holidays that are in that month from a pre-programmed set of holidays. The calendar will function like any other calendar and will include leap years. In this program I used:

	
	• Class (separated into header and .cpp files, containing at least two fields and at least one method that isn’t a constructor, getter, setter, or destructor)
	• Struct(s)
	
	(I really tried to use enums but I wasn't able to fit it in anywhere) :L

The only bug I have found is that if you were to input a valid date but then add any character or string after it'll tell you invalid input but still work, moving you onto the next input and still running correctly. Here is an example:

	Hello. Welcome to Alex's Calendar Application.
	Enter a month (1-12):
	12/
	Enter a day (1-31):
	Error: Invalid input.
	Enter a day (1-31):
	25dwauhi
	Enter a year (1-9999):
	Error: Invalid input.
	Enter a year (1-9999):
	2023:P

	12/25/2023 is a Monday

	December
	2023

	Su   Mo   Tu   We   Th   Fr   Sa
	                         1    2
	3    4    5    6    7    8    9
	10   11   12   13   14   15   16
	17   18   19   20   21   22   23
	24   25   26   27   28   29   30
	31

	Sunday 12/24/2023 is Christmas Eve.
	Monday 12/25/2023 is Christmas Day.
	Sunday 12/31/2023 is New Years Eve.
	
	Thanks you for using Alex's Calendar.
	
	Process finished with exit code 0

This doesn't happen the other way around:

	Hello. Welcome to Alex's Calendar Application.
	Enter a month (1-12):
	d12
	Error: Invalid input.
	Enter a month (1-12):

A future feature that could be added is floating holidays (ones which change each year but are set to x day on y week.) Another feature that could potentially
be addedd is the ability to save and store events like a regular calendar, such as a meeting or event coming up.

Citations (these are directly from the program in order and can be found directly where they are used)
	
	To fix my modulus function - https://www.youtube.com/watch?v=gy3Ni-wFYR4&ab_channel=FastCodeDeveloper
	For my calendar formula - https://cs.uwaterloo.ca/~alopez-o/math-faq/node73.html#:~:text=For%20a%20Gregorian%20date%2C%20add,7%20and%20take%20the%20remainder
	For printing correctly - https://stackoverflow.com/questions/2485963/c-alignment-when-printing-cout
	For input validation - https://stackoverflow.com/questions/19521320/why-do-i-get-an-infinite-loop-if-i-enter-a-letter-rather-than-a-number

I think I earned a 90+ because: I have included numerous Module 1 concepts. I have (nearly) perfect input validation. I have a complex design & purpose. The classes are designed well and
each file is utilized for it's respective usage (calendar.h for headers / declaring, calendar.cpp for defining, complex calculations, and printing, and main.cpp for input validation
