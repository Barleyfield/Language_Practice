class Define:
    KOREAN = 1001
    MATH = 2001

    AB_TYPE = 0
    SAB_TYPE = 1

class Student:
    scoreList = list()
    def __init__(self, studentId, studentName, majorSubject):
        self.__studentId = studentId
        self.__studentName = studentName
        self.__majorSubject = majorSubject
    def addSubjectScore(self, score):
        self.scoreList.append(score)
    def getStudentId(self):
        return self.__studentId
    def setStudentId(self, studendId):
        self.studentId = studentId
    def getStudentName(self):
        return self.__studentName
    def setstudentName(self, studentName):
        self.__studentName = studentName
    def getMajorSubject(self):
        return self.__majorSubject
    def setMajorSubject(self, majorSubject):
        self.__majorSubject = majorSubject
    def getScoreList(self):
        return self.scoreList

class Subject:
    studentList = list()
    def __init__(self, subjectName, subjectId):
        self.subjectName = subjectName
        self.subjectId = subjectId
        self.gradeType = Define.AB_TYPE
    def getSubjectName(self):
        return self.subjectName
    def setSubjectName(self, subjectName):
        self.subjectName = subjectName
    def getSubjectId(self):
        return self.subjectId
    def setSubjectId(self, subjectId):
        self.subjectId = subjectId
    def getStudentList(self):
        return self.studentList
    def getGradeType(self):
        return self.gradeType
    def setGradeType(self, gradeType):
        self.gradeType = gradeType
    def register(self, student):
        self.studentList.append(student)

class School:

    SCHOOL_NAME = "Good School"
    stdList = list()
    sbjList = list()

    def getStudentList(self):
        return self.stdList
    def addStudent(self, student):
        self.stdList.append(student)
    def addSubject(self, subject):
        self.sbjList.append(subject)
    def getSubjectList(self):
        return self.sbjList
    def setsubjectList(subjectList):
        self.sbjList = subjectList

class BasicEvaluation:
    def getGrade(self, point):
        grade = ""
        if((point >= 90) and (point<=100)):
            grade = "A"
        elif(point >= 80):
            grade = "B"
        elif(point >= 70):
            grade = "C"
        elif(point >= 55):
            grade = "D"
        else :
            grade = "F"
        return grade

class MajorEvaluation:
    def getGrade(self, point):
        grade = ""
        if((point >= 95) and (point<=100)):
            grade = "S"
        elif(point >= 90):
            grade = "A"
        elif(point >= 80):
            grade = "B"
        elif(point >= 70):
            grade = "C"
        elif(point >= 60):
            grade = "D"
        else: 
            grade = "F"
        return grade

class GenerateGradeReport:
    TITLE =  "  ::: Student Score =="
    HEADER = "  Name  |   ID   |   Major      |  Score"
    LINE =   "---------------------------------------------------"
    temp_string = ""

    buffer = list()

    def getReport(self, school):
        subjectList = school.getSubjectList()
        for subject in subjectList:
            self.makeHeader(subject)
            self.makeBody(school, subject)
            self.makeFooter()
        return self.buffer

    def makeHeader(self, subject):
        self.buffer.append(GenerateGradeReport.LINE)
        self.buffer.append("\t"+subject.getSubjectName()+GenerateGradeReport.TITLE)
        self.buffer.append(GenerateGradeReport.HEADER)
        self.buffer.append(GenerateGradeReport.LINE)

    def makeBody(self, school, subject):
        studentList = school.getStudentList()
        for student in studentList:
            self.temp_string = student.getStudentName() + " | " + str(student.getStudentId()) + " | " + student.getMajorSubject().getSubjectName() + "\t| "
            my_grade = self.getScoreGrade(student, subject.getSubjectId())
            self.buffer.append(self.temp_string)

    def getScoreGrade(self, student, subjectId):
        scoreList = student.getScoreList()
        majorId = student.getMajorSubject().getSubjectId()
        grade = ""

        gradeEvaluation = [BasicEvaluation(), MajorEvaluation()]

        for score in scoreList:
            if(score.getSubject().getSubjectId() == subjectId):
                if(score.getStudentId() == student.getStudentId()):
                
                    if(score.getSubject().getSubjectId() == majorId):
                        grade = gradeEvaluation[Define.SAB_TYPE].getGrade(score.getPoint())
                    else:
                        grade = gradeEvaluation[Define.AB_TYPE].getGrade(score.getPoint())
                    self.temp_string = self.temp_string + str( score.getPoint() ) + " : " + grade + " | "
                
    def makeFooter(self):
        self.buffer.append("\n")

class Score:
    def __init__(self, studentId, subject, point):
        self.studentId = studentId
        self.subject = subject
        self.point = point
    def getStudentId(self):
        return self.studentId
    def setStudentId(self, studentId):
        self.studentId = studentId
    def getSubject(self):
        return self.subject
    def setSubject(self, subject):
        self.subject = subject
    def getPoint(self):
        return self.point
    def setPoint(self, point):
        self.point = point
    def info(self):
        return "Hakbun : "+str(self.studentId)+","+self.subject.getSubjectName()+":"+str(self.point)
                    

goodSchool = School()
gradeReport = GenerateGradeReport()

def addScoreForStudent(student, subject, point):
    score = Score(student.getStudentId(), subject, point)
    student.addSubjectScore(score)

Korean = Subject("Korean", Define.KOREAN)
Math = Subject("Math", Define.MATH)

goodSchool.addSubject(Korean)
goodSchool.addSubject(Math)

student1 = Student(181213, "S.W. Ahn", Korean)
student2 = Student(151515, "K.H. Kim", Math)
student3 = Student(162020, "D.K. Lee", Math)
student4 = Student(191010, "J.S. Lim", Math)

goodSchool.addStudent(student1)
goodSchool.addStudent(student2)
goodSchool.addStudent(student3)
goodSchool.addStudent(student4)

Korean.register(student1)
Korean.register(student2)
Korean.register(student3)
Korean.register(student4)

Math.register(student1)
Math.register(student2)
Math.register(student3)
Math.register(student4)

addScoreForStudent(student1, Korean, 95)
addScoreForStudent(student1, Math, 56)
addScoreForStudent(student2, Korean, 88)
addScoreForStudent(student2, Math, 77)
addScoreForStudent(student3, Korean, 92)
addScoreForStudent(student3, Math, 68)
addScoreForStudent(student4, Korean, 96)
addScoreForStudent(student4, Math, 87)

report = gradeReport.getReport(goodSchool)
for outline in report:
    print(outline)
        
        
