import csv

# State Class
class State:
    numOfStateObjects = 0
    def __init__(self, stateName, capitol, region, USHS, pop, COVIDCase, COVIDDeaths, vax, MHI, VCR):
        self.stateName = stateName
        self.capitol = capitol
        self.region = region
        self.USHS = USHS
        self.pop = pop
        self.COVIDCase = COVIDCase
        self.COVIDDeaths = COVIDDeaths
        self.vax = vax
        self.MHI = MHI
        self.VCR = VCR

        State.numOfStateObjects += 1

    def setStateName(self, stateName):
        self.stateName = stateName
    def getStateName(self):
        return self.stateName
    def setCapitol(self, capitol):
        self.capitol = capitol
    def getCapitol(self):
        return self.capitol
    def setRegion(self, region):
        self.region = region
    def getRegion(self):
        return self.region
    def setUSHS(self, USHS):
        self.USHS = USHS
    def getUSHS(self):
        return self.USHS
    def setPop(self, pop):
        self.pop = pop
    def getPop(self):
        return self.pop
    def setCOVIDCases(self, COVIDCase):
        self.COVIDCase = COVIDCase
    def getCOVIDCases(self):
        return self.COVIDCase
    def setCOVIDDeaths(self, COVIDDeaths):
        self.COVIDDeaths = COVIDDeaths
    def getCOVIDDeaths(self):
        return self.COVIDDeaths
    def setVax(self, vax):
        self.vax = vax
    def getVax(self):
        return self.vax
    def setMHI(self, MHI):
        self.MHI = MHI
    def getMHI(self):
        return self.MHI
    def setVCR(self, VCR):
        self.VCR = VCR
    def getVCR(self):
        return self.VCR

# Function Definitions

# Main Function
def main():
    print("CAP4630 Project 1\n\n\n"
          "There were 50 state records read from States.csv")
    stateFile = "States.csv"
    # Opening and Storing File
    stateList = fileOpener(stateFile)
    print(stateList[0].getStateName())
    # TODO: TEST
    userChoice = 0
    cont = True
    while cont:
        # Asking the user to choose what to do
        userChoice = options()
        match userChoice:
            case 1:

            case 2:
                sortingAlgorithms(userChoice, stateList)
            case 3:

            case 4:

            case 5:

            case 6:
                cont = False




# File Opener Function
def fileOpener(stateFile):
    try:
        with open(stateFile, "r") as stateFile:
            csvReader = csv.reader(stateFile)
            next(csvReader, None)
            stateList = []

            # TODO: Ugly, may need to fix later
            for row in csvReader:
                State.setStateName(State, row[0])
                State.setCapitol(State, row[1])
                State.setRegion(State, row[2])
                State.setUSHS(State, row[3])
                State.setPop(State, row[4])
                State.setCOVIDCases(State, row[5])
                State.setCOVIDDeaths(State, row[6])
                State.setVax(State, row[7])
                State.setMHI(State, row[8])
                State.setVCR(State, row[9])
                stateList.append(State(State.getStateName(State),
                                       State.getCapitol(State),
                                       State.getRegion(State),
                                       State.getUSHS(State),
                                       State.getPop(State),
                                       State.getCOVIDCases(State),
                                       State.getCOVIDDeaths(State),
                                       State.getVax(State),
                                       State.getMHI(State),
                                       State.getVCR(State)))
        stateFile.close()
    except IOError:
        print("State File Not Found")

    return stateList
    # End of fileOpener()

# Sorting Algorithms
def sortingAlgorithms(userChoice, stateList):
    print("PlaceHolder")
    if userChoice == 2:
        quickSort(stateList, stateList[0].getStateName, stateList[len(stateList)].getStateName)

    # End of sortingAlgorithm

# Options
def options():
    userChoice = input("Please Choose an Option from Below:\n"
                       "1. Print a State Report\n"
                       "2. Sort by State Name\n"                             # Quick Sort
                       "3. Sort by Case Fatality Rate\n"                     # Merge Sort | Rate of Death / COVIDCase
                       "4. Find and Print a State for a Given Name\n"        # Binary Search if sorted, otherwise Sequential Search
                       "5. Print the Spearman's ρ Correlation Matrix\n"
                       "6. Quit\n"
                       "input: ")

    return userChoice



def quickSort(stateList, left, right):
    if (right - left) <= 0:
        return;
    else:
        pivot = stateList[right]                    # rightmost item in the list

        # partition range
        partition = partitionIt(left, right, pivot, stateList)
        quickSort(left, partition - 1)              # Sort left side
        quickSort(partition + 1, right)             # Sort right side
    # End of quickSort()

def partitionIt(left, right, pivot, stateList):
    l = left
    r = right

    while l <= r:
        while l <= right and stateList[l] < pivot:
            l += 1
        while r >= left and stateList[l] > pivot:
            r-= 1

        if l < r:
            swap(l, r)
            l+= 1
            r -= 1
    swap(l, right)
    return l
    # End of partitionIt

#-----------------------------------------------------------------------------------------------------------

#-----------------------------------------------------------------------------------------------------------

main()

