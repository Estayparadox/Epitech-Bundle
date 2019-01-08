//
//  User.swift
//  ToDoList
//
//  Created by Joseph Pereniguez on 20/02/2018.
//  Copyright © 2018 Joseph Pereniguez. All rights reserved.
//

import UIKit

class User: NSObject {
    
    var userID: String!
    var fullName: String!
    var userMail: String!
    var password: String!
    var imagePath: String!
    var projectList = [String]()
    
    static func == (lhs: User, rhs: User) -> Bool {
        return lhs.userMail == rhs.userMail
    }
}

