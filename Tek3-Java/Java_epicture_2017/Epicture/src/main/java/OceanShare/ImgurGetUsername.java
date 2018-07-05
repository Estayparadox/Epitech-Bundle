package OceanShare;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;

import OceanShare.login.ImgurAuthorization;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

public class ImgurGetUsername extends AppCompatActivity {

    public static String TAG = "ImgurGetUsername";

    public void setInputStreamString(String inputStreamString) {
        this.inputStreamString = inputStreamString;
    }

    private class UserData {
        String username;

        public String getUsername() {
            return username;
        }

        public void setUsername(String username) {
            this.username = username;
        }

    }

    String inputStreamString = new String();

    public UserData getUserData() {
        {
            Log.d(TAG, "print un truc");

            Thread T = new Thread(new Runnable() {
                @Override
                public void run() {
                    URL url = null;
                    try {
                        url = new URL("https://api.imgur.com/3/account/me");
                    } catch (MalformedURLException e) {
                        e.printStackTrace();
                    }

                    HttpURLConnection urlConnection = null;
                    try {
                        urlConnection = (HttpURLConnection) url.openConnection();
                        ImgurAuthorization.getInstance().addToHttpURLConnection(urlConnection);
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        if (urlConnection.getResponseCode() == HttpURLConnection.HTTP_OK) {
                            Log.d(TAG, "connection success");
                            try {
                                if (urlConnection.getContentType() == null)
                                    Log.d(TAG, "header null");
                                else
                                    Log.d(TAG, "content type " + urlConnection.getContentType());
                                InputStream in = urlConnection.getInputStream();

                                setInputStreamString(getStringFromInputStream(in));
                            } catch (IOException e) {
                                e.printStackTrace();
                            } finally {
                                urlConnection.disconnect();
                            }
                        } else {
                            Log.i(TAG, "responseCode=" + urlConnection.getResponseCode());
                            Log.d(TAG, "connection failed");
                            urlConnection.disconnect();
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }

                }
            });
            T.start();
            try {
                T.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            UserData userData = new UserData();

            Log.d(TAG, "input : " + inputStreamString);
            JSONObject data = new JSONObject();
            try {
                data = new JSONObject(inputStreamString);
            } catch (JSONException e) {
                e.printStackTrace();
            }
            JSONObject item = new JSONObject();
            try {
                 item = data.getJSONObject("data");
            } catch (JSONException e) {
                e.printStackTrace();
            }
            try {
                userData.username = item.getString("url");
            } catch (JSONException e) {
                e.printStackTrace();
            }

            return userData;
        }
    }

    private static String getStringFromInputStream(InputStream is) {

        BufferedReader br = null;
        StringBuilder sb = new StringBuilder();

        String line;
        try {
            br = new BufferedReader(new InputStreamReader(is));
            while ((line = br.readLine()) != null) {
                sb.append(line);
            }

        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (br != null) {
                try {
                    br.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        return sb.toString();

    }
}
