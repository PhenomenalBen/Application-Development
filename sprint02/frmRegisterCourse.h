#pragma once

namespace AshesiMIS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for frmRegisterCourse
	/// </summary>
	public ref class frmRegisterCourse : public System::Windows::Forms::Form
	{
	public:

		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		MySqlDataAdapter^ sqlDA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlDR;
		DataTable^ dtAvailable = gcnew DataTable();
		DataTable^ dtSelected = gcnew DataTable();
		String^ ConnectionStr = "server=localhost;port=4306;uid=root;pwd=;database=ahsesimis;";
		int currentStudentID = 0;
		int totalCredits = 0;

		frmRegisterCourse(int studentID)
		{
			InitializeComponent();
			currentStudentID = studentID;
			LoadStudentInfo();
			LoadSemesters();
			InitializeSelectedCoursesTable();
			LoadAvailableCourses();
			//
			//TODO: Add the constructor code here
			//
		}
		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmRegisterCourse()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblStudentInfo;

	private: System::Windows::Forms::DataGridView^ dgvAvailableCourses;
	private: System::Windows::Forms::Button^ btnAddSelected;
	private: System::Windows::Forms::Button^ btnRemoveSelected;
	private: System::Windows::Forms::Button^ btnRegister;
	private: System::Windows::Forms::Button^ btnCancel;






	private: System::Windows::Forms::DataGridView^ dgvSelectedCourses;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ cmbSemester;

	private: System::Windows::Forms::Label^ lblTotalCredits;
	private: System::Windows::Forms::TextBox^ txtAcademicYear;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblStudentInfo = (gcnew System::Windows::Forms::Label());
			this->dgvAvailableCourses = (gcnew System::Windows::Forms::DataGridView());
			this->btnAddSelected = (gcnew System::Windows::Forms::Button());
			this->btnRemoveSelected = (gcnew System::Windows::Forms::Button());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->dgvSelectedCourses = (gcnew System::Windows::Forms::DataGridView());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->cmbSemester = (gcnew System::Windows::Forms::ComboBox());
			this->lblTotalCredits = (gcnew System::Windows::Forms::Label());
			this->txtAcademicYear = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAvailableCourses))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSelectedCourses))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(199, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(245, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Course Registration";
			// 
			// lblStudentInfo
			// 
			this->lblStudentInfo->AutoSize = true;
			this->lblStudentInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->lblStudentInfo->Location = System::Drawing::Point(49, 52);
			this->lblStudentInfo->Name = L"lblStudentInfo";
			this->lblStudentInfo->Size = System::Drawing::Size(123, 25);
			this->lblStudentInfo->TabIndex = 1;
			this->lblStudentInfo->Text = L"Student Info:";
			// 
			// dgvAvailableCourses
			// 
			this->dgvAvailableCourses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvAvailableCourses->Location = System::Drawing::Point(54, 89);
			this->dgvAvailableCourses->Name = L"dgvAvailableCourses";
			this->dgvAvailableCourses->RowHeadersWidth = 51;
			this->dgvAvailableCourses->RowTemplate->Height = 24;
			this->dgvAvailableCourses->Size = System::Drawing::Size(645, 150);
			this->dgvAvailableCourses->TabIndex = 2;
			// 
			// btnAddSelected
			// 
			this->btnAddSelected->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAddSelected->Location = System::Drawing::Point(54, 245);
			this->btnAddSelected->Name = L"btnAddSelected";
			this->btnAddSelected->Size = System::Drawing::Size(214, 35);
			this->btnAddSelected->TabIndex = 3;
			this->btnAddSelected->Text = L"Add Selected Courses";
			this->btnAddSelected->UseVisualStyleBackColor = true;
			this->btnAddSelected->Click += gcnew System::EventHandler(this, &frmRegisterCourse::btnAddSelected_Click);
			
			// 
			// btnRemoveSelected
			// 
			this->btnRemoveSelected->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRemoveSelected->Location = System::Drawing::Point(324, 245);
			this->btnRemoveSelected->Name = L"btnRemoveSelected";
			this->btnRemoveSelected->Size = System::Drawing::Size(171, 32);
			this->btnRemoveSelected->TabIndex = 4;
			this->btnRemoveSelected->Text = L"Remove Selected";
			this->btnRemoveSelected->UseVisualStyleBackColor = true;
			this->btnRemoveSelected->Click += gcnew System::EventHandler(this, &frmRegisterCourse::btnRemoveSelected_Click);
			
			// 
			// btnRegister
			// 
			this->btnRegister->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegister->Location = System::Drawing::Point(204, 589);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(188, 41);
			this->btnRegister->TabIndex = 5;
			this->btnRegister->Text = L"Register Courses";
			this->btnRegister->UseVisualStyleBackColor = true;
			this->btnRegister->Click += gcnew System::EventHandler(this, &frmRegisterCourse::btnRegister_Click);
			
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancel->Location = System::Drawing::Point(448, 589);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(104, 41);
			this->btnCancel->TabIndex = 6;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmRegisterCourse::btnCancel_Click);
			// 
			// dgvSelectedCourses
			// 
			this->dgvSelectedCourses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvSelectedCourses->Location = System::Drawing::Point(54, 286);
			this->dgvSelectedCourses->Name = L"dgvSelectedCourses";
			this->dgvSelectedCourses->RowHeadersWidth = 51;
			this->dgvSelectedCourses->RowTemplate->Height = 24;
			this->dgvSelectedCourses->Size = System::Drawing::Size(645, 150);
			this->dgvSelectedCourses->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label4->Location = System::Drawing::Point(49, 508);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(209, 25);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Registration Semester:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label5->Location = System::Drawing::Point(366, 456);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(151, 25);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Academic Year:";
			// 
			// cmbSemester
			// 
			this->cmbSemester->FormattingEnabled = true;
			this->cmbSemester->Location = System::Drawing::Point(264, 512);
			this->cmbSemester->Name = L"cmbSemester";
			this->cmbSemester->Size = System::Drawing::Size(245, 24);
			this->cmbSemester->TabIndex = 11;
			// 
			// lblTotalCredits
			// 
			this->lblTotalCredits->AutoSize = true;
			this->lblTotalCredits->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->lblTotalCredits->Location = System::Drawing::Point(49, 456);
			this->lblTotalCredits->Name = L"lblTotalCredits";
			this->lblTotalCredits->Size = System::Drawing::Size(123, 25);
			this->lblTotalCredits->TabIndex = 12;
			this->lblTotalCredits->Text = L"Total Credits";
			// 
			// txtAcademicYear
			// 
			this->txtAcademicYear->Location = System::Drawing::Point(545, 456);
			this->txtAcademicYear->Name = L"txtAcademicYear";
			this->txtAcademicYear->Size = System::Drawing::Size(154, 22);
			this->txtAcademicYear->TabIndex = 14;
			// 
			// frmRegisterCourse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::RosyBrown;
			this->ClientSize = System::Drawing::Size(760, 667);
			this->Controls->Add(this->txtAcademicYear);
			this->Controls->Add(this->lblTotalCredits);
			this->Controls->Add(this->cmbSemester);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->dgvSelectedCourses);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnRegister);
			this->Controls->Add(this->btnRemoveSelected);
			this->Controls->Add(this->btnAddSelected);
			this->Controls->Add(this->dgvAvailableCourses);
			this->Controls->Add(this->lblStudentInfo);
			this->Controls->Add(this->label1);
			this->Name = L"frmRegisterCourse";
			this->Text = L"Student Course Registration";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAvailableCourses))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSelectedCourses))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:
	void LoadStudentInfo() {
		try {
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT s.StudentID, u.FirstName, u.LastName, p.Programme, s.Level " +
				"FROM students s " +
				"INNER JOIN users u ON s.UserID = u.ID " +
				"INNER JOIN programmes p ON s.ProgrammeID = p.ID " +
				"WHERE s.ID = @id";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@id", currentStudentID);
			sqlDR = sqlCmd->ExecuteReader();

			if (sqlDR->Read()) {
				lblStudentInfo->Text = "Student: " + sqlDR["StudentID"]->ToString() + " - " +
					sqlDR["FirstName"]->ToString() + " " + sqlDR["LastName"]->ToString() +
					" | Programme: " + sqlDR["Programme"]->ToString() +
					" | Level: " + sqlDR["Level"]->ToString();
			}
			sqlDR->Close();
			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error loading student info: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	void LoadSemesters() {
		cmbSemester->Items->Clear();
		cmbSemester->Items->Add("First Semester");
		cmbSemester->Items->Add("Second Semester");
		cmbSemester->Items->Add("Summer Session");
	}

	void InitializeSelectedCoursesTable() {
		dtSelected->Columns->Clear();
		dtSelected->Columns->Add("CourseID", int::typeid);
		dtSelected->Columns->Add("CourseCode", String::typeid);
		dtSelected->Columns->Add("CourseTitle", String::typeid);
		dtSelected->Columns->Add("Credits", int::typeid);
		dgvSelectedCourses->DataSource = dtSelected;
	}

	void LoadAvailableCourses() {
		try {
			if (sqlConn->State == ConnectionState::Open) sqlConn->Close();
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();

			// Get student's level and programme
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT Level, ProgrammeID FROM students WHERE ID = @id";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@id", currentStudentID);
			sqlDR = sqlCmd->ExecuteReader();

			int studentLevel = 0;
			int progID = 0;
			if (sqlDR->Read()) {
				studentLevel = Convert::ToInt32(sqlDR["Level"]);
				progID = Convert::ToInt32(sqlDR["ProgrammeID"]);
			}
			sqlDR->Close();

			// Load courses for student's level and programme
			MySqlDataAdapter^ da = gcnew MySqlDataAdapter(
				"SELECT ID as CourseID, CourseCode, CourseTitle, CourseCredit as Credits, Semester " +
				"FROM courses " +
				"WHERE Level = @level AND Programme = @prog " +
				"ORDER BY CourseCode", sqlConn);
			da->SelectCommand->Parameters->AddWithValue("@level", studentLevel);
			da->SelectCommand->Parameters->AddWithValue("@prog", progID);

			dtAvailable->Clear();
			da->Fill(dtAvailable);
			dgvAvailableCourses->DataSource = dtAvailable;
			dgvAvailableCourses->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error loading courses: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	System::Void btnAddSelected_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dgvAvailableCourses->SelectedRows->Count == 0) {
			MessageBox::Show("Please select a course to add", "Selection Required",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		for each (DataGridViewRow ^ row in dgvAvailableCourses->SelectedRows) {
			int courseID = Convert::ToInt32(row->Cells["CourseID"]->Value);

			// Check if already added
			bool exists = false;
			for each (DataRow ^ dr in dtSelected->Rows) {
				if (Convert::ToInt32(dr["CourseID"]) == courseID) {
					exists = true;
					break;
				}
			}

			if (!exists) {
				DataRow^ newRow = dtSelected->NewRow();
				newRow["CourseID"] = row->Cells["CourseID"]->Value;
				newRow["CourseCode"] = row->Cells["CourseCode"]->Value;
				newRow["CourseTitle"] = row->Cells["CourseTitle"]->Value;
				newRow["Credits"] = row->Cells["Credits"]->Value;
				dtSelected->Rows->Add(newRow);

				totalCredits += Convert::ToInt32(row->Cells["Credits"]->Value);
			}
		}

		UpdateTotalCredits();
	}

	System::Void btnRemoveSelected_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dgvSelectedCourses->SelectedRows->Count == 0) {
			MessageBox::Show("Please select a course to remove", "Selection Required",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		for each (DataGridViewRow ^ row in dgvSelectedCourses->SelectedRows) {
			totalCredits -= Convert::ToInt32(row->Cells["Credits"]->Value);
			dgvSelectedCourses->Rows->Remove(row);
		}

		UpdateTotalCredits();
	}

	System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dtSelected->Rows->Count == 0) {
			MessageBox::Show("Please select at least one course", "No Courses Selected",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		if (cmbSemester->SelectedIndex == -1 || txtAcademicYear->Text->Trim() == "") {
			MessageBox::Show("Please select semester and enter academic year", "Validation Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		String^ semester = cmbSemester->Text;
		String^ academicYear = txtAcademicYear->Text->Trim();

		try {
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;

			int successCount = 0;
			for each (DataRow ^ row in dtSelected->Rows) {
				int courseID = Convert::ToInt32(row["CourseID"]);

				// Check if already registered
				sqlCmd->CommandText = "SELECT * FROM student_courses WHERE StudentID=@stID AND CourseID=@cID " +
					"AND Semester=@sem AND AcademicYear=@year";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@stID", currentStudentID);
				sqlCmd->Parameters->AddWithValue("@cID", courseID);
				sqlCmd->Parameters->AddWithValue("@sem", semester);
				sqlCmd->Parameters->AddWithValue("@year", academicYear);
				sqlDR = sqlCmd->ExecuteReader();

				if (!sqlDR->Read()) {
					sqlDR->Close();

					// Register course
					sqlCmd->CommandText = "INSERT INTO student_courses(StudentID, CourseID, Semester, AcademicYear, Status) " +
						"VALUES (@stID, @cID, @sem, @year, 'Registered')";
					sqlCmd->Parameters->Clear();
					sqlCmd->Parameters->AddWithValue("@stID", currentStudentID);
					sqlCmd->Parameters->AddWithValue("@cID", courseID);
					sqlCmd->Parameters->AddWithValue("@sem", semester);
					sqlCmd->Parameters->AddWithValue("@year", academicYear);
					sqlCmd->ExecuteNonQuery();
					successCount++;
				}
				else {
					sqlDR->Close();
				}
			}

			sqlConn->Close();

			MessageBox::Show("Successfully registered " + successCount + " course(s)", "Success",
				MessageBoxButtons::OK, MessageBoxIcon::Information);

			dtSelected->Clear();
			totalCredits = 0;
			UpdateTotalCredits();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			if (sqlConn->State == ConnectionState::Open) sqlConn->Close();
		}
	}

	System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	void UpdateTotalCredits() {
		lblTotalCredits->Text = "Total Credits: " + totalCredits.ToString();
	}
	};
}
