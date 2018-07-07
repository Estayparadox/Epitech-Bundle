//
//  ViewController.swift
//  IntranetEpitech
//
//  Created by Joseph Pereniguez on 25/03/2016.
//  Copyright © 2016 Joseph Pereniguez. All rights reserved.
//

import UIKit
import Alamofire
import Kingfisher
import SwiftyJSON
import Foundation
import QuartzCore

class ViewController: UIViewController {
    
   // @IBOutlet weak var userName: UILabel!
    
    //@IBOutlet weak var userPhoto: UIImageView!
    
    //@IBOutlet weak var userLogin: UILabel!
    
    //@IBOutlet weak var userPromo: UILabel!
    
    //@IBOutlet weak var userGPA: UILabel!
    
    //@IBOutlet weak var userCredit: UILabel!
    
    var user: userClass!
    
    /*@IBAction func logoutToGoOut(sender: AnyObject) {
        performSegueWithIdentifier("segueLogout", sender: self)
    }*/
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        
    /*APIManager.instanceShared.getUser(user.userLogin) { (json) in
        self.user.seterClass(json)
        self.userName.text = self.user.userName
        self.userPhoto.kf_setImageWithURL(NSURL(string: self.user.userPhoto)!)
        self.userLogin.text = self.user.userLogin
        self.userPromo.text = String(self.user.userPromo)
        //self.userGPA.text = String(self.user.userGPA)
        self.userCredit.text = String(self.user.userCredit)
        self.userPhoto.layer.cornerRadius = 60
        self.userPhoto.clipsToBounds = true;
        }*/

    }
    
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

}