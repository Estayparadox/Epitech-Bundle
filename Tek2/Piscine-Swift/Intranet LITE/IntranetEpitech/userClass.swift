//
//  userClass.swift
//  IntranetEpitech
//
//  Created by Joseph Pereniguez on 25/03/2016.
//  Copyright © 2016 Joseph Pereniguez. All rights reserved.
//

import UIKit
import Alamofire
import Kingfisher
import SwiftyJSON
import PageController
import TVButton

class userClass: NSObject {

    var userName: String!
    var userPassword: String!
    var userPhoto: String!
    var userLogin: String!
    var userPromo: Int!
    //var userGPA: Int!
    var userCredit: Int!

    func seterClass(json: JSON!) {
        self.userName = json["title"].string
        //self.userGPA = json["gpa": "gpa"]
        self.userCredit = json["credits"].int
        self.userPromo = json["promo"].int
        self.userPhoto = json["picture"].string
    }

}