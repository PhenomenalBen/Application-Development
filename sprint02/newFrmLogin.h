#pragma once
#include "user.h"
#include "frmMain.h" 
namespace AshesiMIS {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    /// <summary>
    /// Summary for newFrmLogin
    /// </summary>
    public ref class newFrmLogin : public System::Windows::Forms::Form
    {

    public:
        newFrmLogin(void)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }
        MySqlConnection^ sqlConn = gcnew MySqlConnection();
        MySqlCommand^ sqlCmd = gcnew MySqlCommand();
        MySqlDataAdapter^ sqlDA = gcnew MySqlDataAdapter();
        MySqlDataReader^ sqlDR;
        DataTable^ sqlDT = gcnew DataTable();
        // fixed connection string quoting and formatting
        String^ ConnectionStr = "server=localhost;port=4306;uid=root;pwd=;database=ahsesimis;";

        User^ user = gcnew User();
    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~newFrmLogin()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::TextBox^ txtEmail;
    private: System::Windows::Forms::TextBox^ txtPassword;
    private: System::Windows::Forms::Button^ btnLogin;
    private: System::Windows::Forms::Button^ btnCancel;

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
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->txtEmail = (gcnew System::Windows::Forms::TextBox());
            this->txtPassword = (gcnew System::Windows::Forms::TextBox());
            this->btnLogin = (gcnew System::Windows::Forms::Button());
            this->btnCancel = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AccessibleName = L"";
            this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
            this->label1->Location = System::Drawing::Point(12, 9);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(226, 38);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Login";
            this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
            this->label2->Location = System::Drawing::Point(15, 66);
            this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(80, 29);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Email:";
            this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
            this->label3->Location = System::Drawing::Point(15, 127);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(120, 29);
            this->label3->TabIndex = 2;
            this->label3->Text = L"Password";
            // 
            // txtEmail
            // 
            this->txtEmail->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
            this->txtEmail->Location = System::Drawing::Point(157, 66);
            this->txtEmail->Name = L"txtEmail";
            this->txtEmail->Size = System::Drawing::Size(346, 34);
            this->txtEmail->TabIndex = 3;
            // 
            // txtPassword
            // 
            this->txtPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
            this->txtPassword->Location = System::Drawing::Point(157, 127);
            this->txtPassword->Name = L"txtPassword";
            this->txtPassword->PasswordChar = '*';
            this->txtPassword->Size = System::Drawing::Size(302, 34);
            this->txtPassword->TabIndex = 4;
            // 
            // btnLogin
            // 
            this->btnLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
            this->btnLogin->Location = System::Drawing::Point(157, 185);
            this->btnLogin->Name = L"btnLogin";
            this->btnLogin->Size = System::Drawing::Size(113, 36);
            this->btnLogin->TabIndex = 5;
            this->btnLogin->Text = L"Login";
            this->btnLogin->UseVisualStyleBackColor = true;
            this->btnLogin->Click += gcnew System::EventHandler(this, &newFrmLogin::btnLogin_Click);
            // 
            // btnCancel
            // 
            this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
            this->btnCancel->Location = System::Drawing::Point(335, 185);
            this->btnCancel->Name = L"btnCancel";
            this->btnCancel->Size = System::Drawing::Size(113, 36);
            this->btnCancel->TabIndex = 6;
            this->btnCancel->Text = L"Cancel";
            this->btnCancel->UseVisualStyleBackColor = true;
            this->btnCancel->Click += gcnew System::EventHandler(this, &newFrmLogin::btnCancel_Click);
            // 
            // newFrmLogin
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Highlight;
            this->ClientSize = System::Drawing::Size(700, 400);
            this->Controls->Add(this->btnCancel);
            this->Controls->Add(this->btnLogin);
            this->Controls->Add(this->txtPassword);
            this->Controls->Add(this->txtEmail);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"newFrmLogin";
            this->Text = L"Ashesi MIS";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    
    private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ email = txtEmail->Text->Trim();
        String^ password = txtPassword->Text->Trim();
        if (email->Length == 0 || password->Length == 0) {
            MessageBox::Show(L"Please enter an email and password", L"", MessageBoxButtons::OK);
            return;
        }

        try {
            sqlConn->ConnectionString = ConnectionStr;
            sqlConn->Open();
            sqlCmd->Connection = sqlConn;
            sqlCmd->CommandText = "SELECT * FROM users WHERE email=@email AND password=@pwd";
            sqlCmd->Parameters->Clear();
            sqlCmd->Parameters->AddWithValue("@email", email);
            sqlCmd->Parameters->AddWithValue("@pwd", password);
            sqlDR = sqlCmd->ExecuteReader();
            if (sqlDR->Read()) {
                user->id = Convert::ToInt32(sqlDR["ID"]);
                user->fName = sqlDR["FirstName"]->ToString();
                user->lName = sqlDR["LastName"]->ToString();
                user->email = sqlDR["Email"]->ToString();
                user->password = sqlDR["Password"]->ToString();
                user->roleNum = Convert::ToInt32(sqlDR["role"]);

                sqlDR->Close(); // Close first reader

                // Get student or faculty ID based on role
                if (user->roleNum == 3) { // Student
                    sqlCmd->CommandText = "SELECT ID FROM students WHERE UserID = @userID";
                    sqlCmd->Parameters->Clear();
                    sqlCmd->Parameters->AddWithValue("@userID", user->id);
                    sqlDR = sqlCmd->ExecuteReader();
                    if (sqlDR->Read()) {
                        user->studentID = Convert::ToInt32(sqlDR["ID"]);
                    }
                    sqlDR->Close();
                }
                else if (user->roleNum == 2) { // Faculty
                    sqlCmd->CommandText = "SELECT ID FROM faculty WHERE UserID = @userID";
                    sqlCmd->Parameters->Clear();
                    sqlCmd->Parameters->AddWithValue("@userID", user->id);
                    sqlDR = sqlCmd->ExecuteReader();
                    if (sqlDR->Read()) {
                        user->facultyID = Convert::ToInt32(sqlDR["ID"]);
                    }
                    sqlDR->Close();
                }

                // Show welcome message
                MessageBox::Show(String::Format(L"Welcome {0}!", user->fName), L"Login Successful", MessageBoxButtons::OK);

                // Create and show main form
                AshesiMIS::frmMain^ mainForm = gcnew AshesiMIS::frmMain(user);
                mainForm->Show();

                // Hide login form
                this->Hide();
            }
            else {
                MessageBox::Show(L"Email or Password is incorrect", L"Login Failed", MessageBoxButtons::OK);
                return;
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show(String::Format(L"Failed to connect to database: {0}", ex->Message),
                L"Database Connection Error", MessageBoxButtons::OK);
        }
        finally {
            if (sqlConn->State == ConnectionState::Open) {
                sqlConn->Close();
            }
        }
    }
           private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }
    };
}
