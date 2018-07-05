package OceanShare;

import android.net.Uri;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.google.android.gms.appindexing.Action;
import com.google.android.gms.appindexing.AppIndex;
import com.google.android.gms.appindexing.Thing;
import com.google.android.gms.common.api.GoogleApiClient;
import OceanShare.login.ImgurAuthorization;
import com.squareup.picasso.Picasso;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

import static android.os.SystemClock.sleep;

public class ImgurShowTask extends AppCompatActivity  {


    private static class Photo {
        String id;
        String title;
    }

    public void setInputStreamString(String inputStreamString) {
        this.inputStreamString = inputStreamString;
    }

    String inputStreamString = new String();

    public static String TAG = "ImgurShowTask";

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_show);

        Thread T = new Thread(new Runnable(){
            @Override
            public void run() {
                URL url = null;
                try {
                    url = new URL("https://api.imgur.com/3/account/me/images");
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
                        Log.d(TAG,"Connection success");
                        try {
                            if (urlConnection.getContentType() == null)
                                Log.d(TAG,"Error : header");
                            else
                                Log.d(TAG,"Content :" + urlConnection.getContentType());
                            InputStream in = urlConnection.getInputStream();

                             setInputStreamString(getStringFromInputStream(in));
                        } catch (IOException e) {
                            e.printStackTrace();
                        } finally {
                            urlConnection.disconnect();
                        }
                    }
                    else {
                        Log.i(TAG, "responseCode=" + urlConnection.getResponseCode());
                        Log.d(TAG, "Connection failed");
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

        Log.d(TAG,"input : " + inputStreamString);
        JSONObject data = new JSONObject();
        try {
            data = new JSONObject(inputStreamString);
        } catch (JSONException e) {
            e.printStackTrace();
        }
        JSONArray items = new JSONArray();
        try {
            items = data.getJSONArray("data");
        } catch (JSONException e) {
            e.printStackTrace();
        }

        final List<Photo> photos = new ArrayList<>();

        for (int i = 0; i < items.length(); i++) {
            JSONObject item = null;
            try {
                item = items.getJSONObject(i);
            } catch (JSONException e) {
                e.printStackTrace();
            }
            Photo photo = new Photo();
            try {
                photo.id = item.getString("id");
            } catch (JSONException e) {
                e.printStackTrace();
            }
            try {
                photo.title = item.getString("title");
            } catch (JSONException e) {
                e.printStackTrace();
            }

            photos.add(photo); // Add photo to list
            runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    render(photos);
                }
            });

        }
       // fetchData();
    }

        // ATTENTION: This was auto-generated to implement the App Indexing API.
        // See https://g.co/AppIndexing/AndroidStudio for more information.

    private static class PhotoVH extends RecyclerView.ViewHolder {
        ImageView photo;
        TextView title;

        public PhotoVH(View itemView) {
            super(itemView);
        }
    }


   /* private void fetchData() {
        httpClient = new OkHttpClient.Builder().build();
    }*/

    private void render(final List<Photo> photos) {
        RecyclerView rv = (RecyclerView) findViewById(R.id.rv_of_photos);
        rv.setLayoutManager(new LinearLayoutManager(this));
        RecyclerView.Adapter<PhotoVH> adapter = new RecyclerView.Adapter<PhotoVH>() {
            @Override
            public PhotoVH onCreateViewHolder(ViewGroup parent, int viewType) {
                PhotoVH vh = new PhotoVH(getLayoutInflater().inflate(R.layout.item, null));
                vh.photo = (ImageView) vh.itemView.findViewById(R.id.photo);
                vh.title = (TextView) vh.itemView.findViewById(R.id.title);
                return vh;
            }

            @Override
            public void onBindViewHolder(PhotoVH holder, int position) {
                Picasso.with(ImgurShowTask.this).load("https://i.imgur.com/" +
                        photos.get(position).id + ".jpg").into(holder.photo);
                holder.title.setText(photos.get(position).title);
            }

            @Override
            public int getItemCount() {
                return photos.size();
            }
        };
        rv.setAdapter(adapter);
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
