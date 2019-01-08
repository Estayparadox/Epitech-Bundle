//
//  SignupViewController.swift
//  ToDoList
//
//  Created by Joseph Pereniguez on 19/02/2018.
//  Copyright © 2018 Joseph Pereniguez. All rights reserved.
//

import UIKit
import Firebase

class SignupViewController: UIViewController, UIImagePickerControllerDelegate, UINavigationControllerDelegate {

    @IBOutlet weak var nameField: UITextField!
    @IBOutlet weak var emailField: UITextField!
    @IBOutlet weak var passwordField: UITextField!
    @IBOutlet weak var verifPassword: UITextField!
    @IBOutlet weak var profilePicture: UIImageView!
    @IBOutlet weak var signupButton: UIButton!
    @IBOutlet weak var cancelButton: UIButton!
    
    let picker = UIImagePickerController()
    var userStorage: FIRStorageReference!
    var ref: FIRDatabaseReference!
    
    func UIColorFromRGB(rgbValue: UInt) -> UIColor {
        return UIColor(
            red: CGFloat((rgbValue & 0xFF0000) >> 16) / 255.0,
            green: CGFloat((rgbValue & 0x00FF00) >> 8) / 255.0,
            blue: CGFloat(rgbValue & 0x0000FF) / 255.0,
            alpha: CGFloat(1.0)
        )
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()

        picker.delegate = self
        
        let storage = FIRStorage.storage().reference(forURL: "gs://todolist-d6f31.appspot.com")
        
        ref = FIRDatabase.database().reference()
        userStorage = storage.child("users")
        
        let color1 = UIColorFromRGB(rgbValue: 0xfc4a1a)
        let color2 = UIColorFromRGB(rgbValue: 0xf7b733)
        let gradient = CAGradientLayer()
        gradient.frame = view.bounds
        gradient.colors = [color1.cgColor, color2.cgColor]
        view.layer.addSublayer(gradient)
        self.view.layer.insertSublayer(gradient, at: 0)

    }
    
    @IBAction func cancel(_ sender: UIButton) {
        
        dismiss(animated: true)
        
        emailField.resignFirstResponder()
        passwordField.resignFirstResponder()
        
        cancelButton.isHidden = true
        
    }
    
    @IBAction func SelectPicture(_ sender: UIButton) {
        
        picker.allowsEditing = true
        picker.sourceType = .photoLibrary
        
        present(picker, animated: true, completion: nil)
    }
    
    func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [String : Any]) {
        if let image = info[UIImagePickerControllerEditedImage] as? UIImage {
            self.profilePicture.image = image
            // signupButton.isHidden = false
        }
        self.dismiss(animated: true, completion: nil)
    }

    @IBAction func Signup(_ sender: UIButton) {

        
        guard nameField.text != "", emailField.text != "", passwordField.text != "", verifPassword.text != "" else { return }
        
        if passwordField.text == verifPassword.text {
            FIRAuth.auth()?.createUser(withEmail: emailField.text!, password: passwordField.text!, completion: { (user, error) in
                
                
                if let error = error {
                    print(error.localizedDescription)
                }
                
                if let user = user {
                    
                    let changeRequest = FIRAuth.auth()!.currentUser!.profileChangeRequest()
                    changeRequest.displayName = self.nameField.text!
                    changeRequest.commitChanges(completion: nil)
                    
                    let imageRef = self.userStorage.child("\(user.uid).jpg")
                    
                    let data = UIImageJPEGRepresentation(self.profilePicture.image!, 0.5)
                    
                    let uploadTask = imageRef.put(data!, metadata: nil, completion: { (metadata, err) in
                        if err != nil {
                            print(err!.localizedDescription)
                        }
                        
                        
                        imageRef.downloadURL(completion: { (url, er) in
                            if er != nil {
                                print(er!.localizedDescription)
                            }
                            
                            
                            if let url = url {
                                
                                let userInfo: [String : Any] = ["uid" : user.uid,
                                                                "full name" : self.nameField.text!,
                                                                "email" : self.emailField.text!,
                                                                "password" : self.passwordField.text!,
                                                                "urlToImage" : url.absoluteString]
                                
                                self.ref.child("users").child(user.uid).setValue(userInfo)
                                
                                
                                let vc = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(withIdentifier: "navVC")
                                
                                self.present(vc, animated: true, completion: nil)
                                
                            }
                        })
                    })
                    uploadTask.resume()
                }
            })
            
        } else {
            print("Password does not match")
        }
    }
}

extension SignupViewController: UITextFieldDelegate {
    
    @IBAction func passwordDidFinish(_ sender: UITextField) {
        
        if signupButton.isHidden {
            signupButton.isHidden = false
        }
        
    }
    
    @IBAction func nameDidChange(_ sender: UITextField) {
        
        if cancelButton.isHidden {
            self.passwordField.text?.removeAll()
            cancelButton.isHidden = false
            
        }
    
    }
    
    @IBAction func emailDidChange(_ sender: UITextField) {
    
        if cancelButton.isHidden {
            self.passwordField.text?.removeAll()
            cancelButton.isHidden = false
            
        }
    
    }
    
    @IBAction func passwordDidChange(_ sender: UITextField) {
    
        if cancelButton.isHidden {
            self.passwordField.text?.removeAll()
            cancelButton.isHidden = false
            
        }
    
    }
    
    @IBAction func verifDidChange(_ sender: UITextField) {
    
        if cancelButton.isHidden {
            self.passwordField.text?.removeAll()
            cancelButton.isHidden = false
            
        }
    
    }
    
}
