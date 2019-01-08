//
//  userClass.swift
//  Epispy 2.0
//
//  Created by Joseph Pereniguez on 25/04/2016.
//  Copyright © 2016 Joseph Pereniguez. All rights reserved.
//

import UIKit
import Alamofire
import Kingfisher
import SwiftyJSON

class userClass: NSObject {
    
    var userName: String!
    var userPassword: String!
    var userPhoto: String!
    var userLogin: String!
    var userPromo: Int!
    //var userGPA: Int!
    var userCredit: Int!
    
    func seterClass(_ json: JSON!) {
        self.userName = json["title"].string
        //self.userGPA = json["gpa": "gpa"]
        self.userCredit = json["credits"].int
        self.userPromo = json["promo"].int
        self.userPhoto = json["picture"].string
    }
    
}
