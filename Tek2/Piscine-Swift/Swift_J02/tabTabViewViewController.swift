//
//  tabTabViewViewController.swift
//  tuto2
//
//  Created by Joseph Pereniguez on 22/03/2016.
//  Copyright © 2016 Joseph Pereniguez. All rights reserved.
//

import UIKit

class tabTabViewViewController: UIViewController {

    @IBAction func myPrevious(sender: AnyObject) {
        performSegueWithIdentifier("mySegue2", sender: self)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
