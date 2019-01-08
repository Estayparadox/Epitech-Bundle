//
//  Project.swift
//  ToDoList
//
//  Created by Joseph Pereniguez on 20/02/2018.
//  Copyright © 2018 Joseph Pereniguez. All rights reserved.
//

import UIKit

class Project: NSObject {

    var projectID: String!
    var projectName: String!
    var ownerID: String!
    var projectDcpt: String?
    var taskList = [Task]()
    var contributors = [User]()
    
    static func == (lhs: Project, rhs: Project) -> Bool {
        return lhs.projectName == rhs.projectName
    }
    
}
