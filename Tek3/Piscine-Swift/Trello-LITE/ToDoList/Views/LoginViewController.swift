//
//  LoginViewController.swift
//  ToDoList
//
//  Created by Joseph Pereniguez on 19/02/2018.
//  Copyright © 2018 Joseph Pereniguez. All rights reserved.
//

import UIKit
import Firebase
import FBSDKLoginKit


class LoginViewController: UIViewController {

    // MARK: Outlets
    
    @IBOutlet weak var cancelButton: UIButton!
    @IBOutlet weak var emailField: UITextField!
    @IBOutlet weak var passwordField: UITextField!
    @IBOutlet weak var button: UIButton!
    
    // MARK: Radiant background
    
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
        
        let color1 = UIColorFromRGB(rgbValue: 0xfc4a1a)
        let color2 = UIColorFromRGB(rgbValue: 0xf7b733)
        let gradient = CAGradientLayer()
        gradient.frame = view.bounds
        gradient.colors = [color1.cgColor, color2.cgColor]
        view.layer.addSublayer(gradient)
        self.view.layer.insertSublayer(gradient, at: 0)
        
    }

    // MARK: Actions
    
    @IBAction func facebookLogin(_ sender: UIButton) {
        let fbLoginManager = FBSDKLoginManager()
        fbLoginManager.logIn(withReadPermissions: ["public_profile", "email"], from: self) { (result, error) in
            if let error = error {
                print("Failed to login: \(error.localizedDescription)")
                return
            }
            
            guard let accessToken = FBSDKAccessToken.current() else {
                print("Failed to get access token")
                return
            }
            
            let credential = FIRFacebookAuthProvider.credential(withAccessToken: accessToken.tokenString)
            
            // Perform login by calling Firebase APIs
            FIRAuth.auth()?.signIn(with: credential, completion: { (user, error) in
                if let error = error {
                    print("Login error: \(error.localizedDescription)")
                    let alertController = UIAlertController(title: "Login Error", message: error.localizedDescription, preferredStyle: .alert)
                    let okayAction = UIAlertAction(title: "OK", style: .cancel, handler: nil)
                    alertController.addAction(okayAction)
                    self.present(alertController, animated: true, completion: nil)
                    
                    return
                }
                
                // Present the main view
                if let viewController = self.storyboard?.instantiateViewController(withIdentifier: "navVC") {
                    UIApplication.shared.keyWindow?.rootViewController = viewController
                    self.dismiss(animated: true, completion: nil)
                }
                
            })
            
        }
    }
    
    @IBAction func cancel(_ sender: UIButton) {
      
        dismiss(animated: true)
        
        emailField.resignFirstResponder()
        passwordField.resignFirstResponder()
        
        button.isHidden = true
        cancelButton.isHidden = true
    }
    
    @IBAction func loginButton(_ sender: UIButton) {
      
        guard emailField.text != "", passwordField.text != "" else {return}
        FIRAuth.auth()?.signIn(withEmail: emailField.text!, password: passwordField.text!, completion: { (user, error) in
           
            if let error = error {
                print(error.localizedDescription)
            }
           
            if let user = user {
                let vc = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(withIdentifier: "navVC")
                
                self.present(vc, animated: true, completion: nil)
            }
        })
    }
}

extension LoginViewController: UITextFieldDelegate {
    @IBAction func emailDidChange(_ sender: UITextField) {
        if cancelButton.isHidden {
            cancelButton.isHidden = false
        }
    }
    
    @IBAction func passwordDidChange(_ sender: UITextField) {
        if button.isHidden {
            button.isHidden = false
        }
        
        if cancelButton.isHidden {
            cancelButton.isHidden = false
        }
        
        UIView.animate(withDuration: 0.3, animations: {
            self.view.layoutIfNeeded()
        })
    }
}
