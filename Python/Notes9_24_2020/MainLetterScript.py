from LetterFunctions import *

""" This is a script to do a small main merge to make a custom letter to magic beings.
    To Run:
    [user@machine directory]$ python MainLetterScript.py <CSV File Address List>
"""

# =============================================================
# READ IN COMMAND LINE ARGUMENTS
# =============================================================
if (len(sys.argv)) != 2:
    print("To Run: python MainLetterScript.py AddressList.csv")
else:
    print("Using addresses from the file", str(sys.argv[1]))
    dataFile = str(sys.argv[1])

# =============================================================
# OPEN FILES
# =============================================================
AddressData = open(dataFile,"r")

# =============================================================
# READ DATA FROM FILE LINE BY LINE
# =============================================================
print("Reading from file " + dataFile)

AddressList = []
for line in AddressData.readlines():
    print("line", line)
    First, Last, Address1, Address2 = map(str,line.split(','))
    CurrentAddress = Address(First, Last, Address1, Address2)
    AddressList.append(CurrentAddress) 

# =============================================================
# WRITE OUT THE FORM LETTERS
# =============================================================
for item in range(len(AddressList)):
    Letter = DocumentText(AddressList[item])
    Letter.WriteLetter()
