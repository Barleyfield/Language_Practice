class Define:
    KOREAN = 1001
    MATH = 2001

    AB_TYPE = 0
    SAB_TYPE = 1

class Student:
    scoreList = list()
    def __init__(self, studentId, studentName, majorSubject):
        self.studentId = studentId
        self.studentName = studentName
        self.majorSubject = majorSubject
    def addSubjectScore(self, score):
        self.scoreList.append(score)
    def getStudentId(self):
        return self.studentId
    def setStudentId(self, studentId):
        self.studentId = studentId
    def getStudentName(self):
        return self.studentName
    def setstudentName(self, studentName):
        self.studentName = studentName
    def getMajorSubject(self):
        return self.majorSubject
    def setMajorSubject(self, majorSubject):
        self.majorSubject = majorSubject
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
    def setsubjectList(self, subjectList):
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
		
	# 새 학생 등록 후 report 출력 시 이전 report와 같이 출력하는 경우가 있어 초기화 함수 구현
    def bufferFlush(self) :
        self.buffer = list()

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
                    

# 클래스와 구분하기 위해 main 추가 
if __name__ == '__main__' :

	goodSchool = School()
	gradeReport = GenerateGradeReport()
	
	def addScoreForStudent(student, subject, point):
	    score = Score(student.getStudentId(), subject, point)
	    student.addSubjectScore(score)
	
	Korean = Subject("Korean", Define.KOREAN)
	Math = Subject("Math", Define.MATH)
	
	goodSchool.addSubject(Korean)
	goodSchool.addSubject(Math)
	
	# --- 여기서부터 문제 2 부분 ----
	
	dataList = list()
	scoreKorean = [95,88,92,96]
	scoreMath = [56,77,68,87]
	
	dataList.append(Student(181213, "S.W. Ahn", Korean))
	dataList.append(Student(151515, "K.H. Kim", Math))
	dataList.append(Student(162020, "D.K. Lee", Math))
	dataList.append(Student(191010, "J.S. Lim", Math))
	
	i = 0
	for data in dataList :
		goodSchool.addStudent(data)
		Korean.register(data)
		Math.register(data)
		addScoreForStudent(data, Korean, scoreKorean[i])
		addScoreForStudent(data, Math, scoreMath[i])
		i = i + 1
		
	report = gradeReport.getReport(goodSchool)
	for outline in report:
	    print(outline)
	
	# report 내용 초기화
	report = gradeReport.bufferFlush()
	
	# --- 여기까지 문제 2 부분 ----
	
	# --- 여기서부터 문제 3 부분 ---
	
	newStudentList = list()		# 새로 입력할 학생의 정보를 저장하는 리스트
	
	while True :
		studentId_input = int(input("Student ID : "))
		studentName_input = input("Student Name : ")
		studentMajorSubject = int(input("Major Subject (1.Korean, 2.Mathmatics) : "))	# 전공과목
		studentTestSubject = int(input("Test Subject (1.Korean, 2.Mathmatics) : ")) 	# 시험봤던 과목
		studentScore = int(input("Test Subject Score : "))	# 시험봤던 과목의 점수 
		
		# 중복 검사
		# 이름, 학번 모두 같은 항목이 이미 등록되었는지 확인
		
		isStudentRegistered = False
		studentIndex = 0
		for i in range(len(newStudentList)) :
			duplicateCounter = 0
			# 학번 중복 검사
			if (studentId_input == newStudentList[i].getStudentId()) :
				duplicateCounter += 1
			
			# 이름 중복 검사
			if (studentName_input == newStudentList[i].getStudentName()) :
				duplicateCounter += 1
			
			# 둘 다 중복이면 break
			if(duplicateCounter == 2) :			
				isStudentRegistered = True
				studentIndex = i 			# 원래 있는 학생의 인덱스(위치) 구하기 
				break
			
		# 처음 등록하는 학생
		if(isStudentRegistered == False) :
			# 전공과목이 국어
			if(studentMajorSubject == 1) :	
				newStudent = Student(studentId_input, studentName_input, Korean)
			# 전공과목이 수학
			else :
				newStudent = Student(studentId_input, studentName_input, Math)
			
			newStudentList.append(newStudent)	# std_info.dat 작성용
			goodSchool.addStudent(newStudent)	# 학교에 학생 등록
			
			# 시험봤던 과목이 국어
			if(studentTestSubject == 1) :
				Korean.register(newStudent)
				addScoreForStudent(newStudent, Korean, studentScore)
			# 시험봤던 과목이 수학
			else :
				Math.register(newStudent)
				addScoreForStudent(newStudent, Math, studentScore)
		# 이미 존재하는 학생
		else :
			# 시험봤던 과목이 국어
			if(studentTestSubject == 1) :
				addScoreForStudent(newStudentList[studentIndex], Korean, studentScore)
			# 시험봤던 과목이 수학
			else :
				addScoreForStudent(newStudentList[studentIndex], Math, studentScore)		

		# 계속할 것인지 그만둘 것인지 결정
		continueOrQuit = int(input("Add another student information (1.yes, 2.no) : "))
		if(continueOrQuit == 2) :
			break
		else :
			continue
	
	print("\n========Print scores of new students========\n")
	report = gradeReport.getReport(goodSchool)

	# for outline in report:
	#   print(outline)
	
	for i in range(len(report)) :
		print(report[i])
	
		
	# --- 여기까지 문제 3 부분 ---
	
	# --- 여기서부터 문제 4 부분 ---
	
	# 파일 저장하기
	f = open('std_info.dat', 'w+')
	f.writelines("Index :  ID,    Name,    Major Subject\n")
	for i in range(len(newStudentList)) :
		if (newStudentList[i].getMajorSubject().getSubjectName() == "Korean") :
			f.writelines("\t" + str(i) + " : " + str(newStudentList[i].getStudentId()) + 
				   "," + "\t" + newStudentList[i].getStudentName() +
				   "," +"\t\t"+ "국어" + "\n"
				 )
		else : 
			f.writelines("\t" + str(i) + " : " + str(newStudentList[i].getStudentId()) + 
				   "," + "\t" + newStudentList[i].getStudentName() +
				   "," +"\t\t"+ "수학" + "\n"
				 )
	f.close()
	
	# 저장한 파일 읽어오기
	f = open('std_info.dat', 'r')
	print(f.read())
	
	
	# --- 여기까지 문제 4 부분 ---
	
	

