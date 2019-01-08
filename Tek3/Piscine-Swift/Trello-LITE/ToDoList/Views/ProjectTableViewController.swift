//
//  ProjectTableViewController.swift
//  ToDoList
//
//  Created by Joseph Pereniguez on 24/02/2018.
//  Copyright © 2018 Joseph Pereniguez. All rights reserved.
//

import UIKit
import Firebase

class ProjectTableViewController: UITableViewController {
    
    // MARK: variables
    
    var project = [Project]()
    var user = [User]()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        retrieveProjects()
        
    }

    func retrieveProjects() {
        let ref = FIRDatabase.database().reference()
        
        ref.child("users").queryOrderedByKey().observeSingleEvent(of: .value, with: { snapshot in
            
            let users = snapshot.value as! [String: AnyObject]
            self.user.removeAll()
            
            for (_, value) in users {
                if let uid = value["uid"] as? String {
                    if uid == FIRAuth.auth()!.currentUser!.uid { // find the current user
                        let currentUser = User()
                        if let fullName = value["full name"] as? String,
                            let imagePath = value["urlToImage"] as? String,
                            let email = value["email"] as? String,
                            let password = value["password"] as? String {
                            currentUser.fullName = fullName
                            currentUser.userMail = email
                            currentUser.password = password
                            currentUser.imagePath = imagePath
                            
                            if let projects = value["projects"] as? [String : String] {
                                for (_, value) in projects{
                                    let newProject = Project()
                                    currentUser.projectList.append(value)
                                    if let val = value as? String {
                                        newProject.projectName = val
                                        newProject.ownerID = currentUser.userID
                                        self.project.append(newProject)
                                    }
                                }
                            }
                            self.user.append(currentUser)
                        }
                    }
                }
            }
            self.tableView.reloadData()
        })
        ref.removeAllObservers()
    }
    
    /*func findProject() {
        for (value) in self.user[indexPath.row].projectList {
            cell.projectName.text = value
        }
    }*/
    
    // MARK: Actions
    
    @IBAction func logout(_ sender: Any) {
        try! FIRAuth.auth()!.signOut()
        if let storyboard = self.storyboard {
            let vc = storyboard.instantiateViewController(withIdentifier: "LoginView") as! UIViewController
            self.present(vc, animated: false, completion: nil)
        }
        
        //try! FIRAuth.auth()!.signOut()
        //self.dismiss(animated: true, completion: nil)
    }
    
    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "ProjectCell", for: indexPath) as! ProjectCell
        
        cell.projectName.text = self.project[indexPath.row].projectName
        // cell.projectName.text = self.user[indexPath.row].projectList[indexPath.row]
        
        return cell
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return project.count ?? 0
    }
    
    // MARK: Table view delegate
    
    override func tableView(_ tableView: UITableView, trailingSwipeActionsConfigurationForRowAt indexPath: IndexPath) -> UISwipeActionsConfiguration? {
        let action = UIContextualAction(style: .destructive, title: "Delete") { (action, view, completion) in
            // TODO: Delete todo
            
            /*if let projects = snapshot.value as? [String : AnyObject] {
             for (ke, value) in projects {
             if value as? String == currentProject?.text {
             ref.child("users").child(uid).child("projects/\(ke)").removeValue()
             }
             }
             }*/
            
            
            completion(true)
        }
        action.image = #imageLiteral(resourceName: "Trash")
        action.backgroundColor = .red
        
        return UISwipeActionsConfiguration(actions: [action])
    }
    
    override func tableView(_ tableView: UITableView, leadingSwipeActionsConfigurationForRowAt indexPath: IndexPath) -> UISwipeActionsConfiguration? {
        let action = UIContextualAction(style: .destructive, title: "Check") { (action, view, completion) in
            // TODO: Delete todo
            completion(true)
        }
        action.image = #imageLiteral(resourceName: "Check")
        action.backgroundColor = .green
        
        return UISwipeActionsConfiguration(actions: [action])
    }

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
