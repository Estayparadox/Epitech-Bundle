package OceanShare;

import android.app.Application;
import android.content.Context;
import android.content.pm.PackageManager.NameNotFoundException;
import android.util.Log;

public class ImgurSampleApplication extends Application {
	
	private static final String TAG = ImgurSampleApplication.class.getSimpleName();

    private static Context context;

    public void onCreate(){
        super.onCreate();
        ImgurSampleApplication.context = getApplicationContext();
    }

    public static Context getAppContext() {
        return ImgurSampleApplication.context;
    }
    
    public static String getVersionName() {
		try {
			return context.getPackageManager().getPackageInfo(context.getPackageName(), 0).versionName;
		} catch (NameNotFoundException e) {
			return "1.0";
		}
    }

}
