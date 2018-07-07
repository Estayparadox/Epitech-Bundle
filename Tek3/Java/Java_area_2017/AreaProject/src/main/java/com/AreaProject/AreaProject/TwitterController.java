package com.AreaProject.AreaProject;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

@Controller
public class TwitterController {

    @GetMapping("/sendMsg")
    public String viewRegistration(Model model) {
        model.addAttribute("TwitterApplication", new TwitterApplication());
        return "sendMsg";
    }

    @PostMapping("/sendMsg")
    public String processRegistration(@ModelAttribute TwitterApplication twitterApplication) {
        return "sendingSucces";
    }
}
