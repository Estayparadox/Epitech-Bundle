//
//  Task.swift
//  ToDoList
//
//  Created by Joseph Pereniguez on 20/02/2018.
//  Copyright © 2018 Joseph Pereniguez. All rights reserved.
//

import UIKit

class Task: NSObject {

    var taskName: String!
    var taskID: String!
    var taskDcpt: String?
    var taskPriority: Int!
    var deadLine: Date!
    
    static func == (lhs: Task, rhs: Task) -> Bool {
        return lhs.taskName == rhs.taskName
    }
    
}

