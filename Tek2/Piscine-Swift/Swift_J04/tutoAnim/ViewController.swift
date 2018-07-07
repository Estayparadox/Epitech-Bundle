//
//  ViewController.swift
//  tutoAnim
//
//  Created by Joseph Pereniguez on 22/03/2016.
//  Copyright © 2016 Joseph Pereniguez. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    var blurView = UIVisualEffectView()
    var blurEffect = UIBlurEffect(style: UIBlurEffectStyle.Light)
    
    @IBOutlet weak var myCheck: UIButton!
    
    @IBOutlet weak var photoSpace: UIImageView!
    
    @IBAction func myAction(sender: AnyObject) {
        UIView.animateWithDuration(0.5, delay: 0.3, usingSpringWithDamping: 0.5, initialSpringVelocity: 0.3, options: [], animations: { () -> Void in
            //self.photoSpace.alpha = 0.5
            self.photoSpace.center = self.view.center
            }) { (Bool) -> Void in
                self.myCheck.tintColor = UIColor.myRed()
                self.blurView.frame = self.photoSpace.frame
                self.view.addSubview(self.blurView)
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        //photoSpace.alpha = 0.0
        blurView = UIVisualEffectView(effect: blurEffect)
        
    // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
}

