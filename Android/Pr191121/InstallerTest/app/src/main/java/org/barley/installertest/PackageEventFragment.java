package org.barley.installertest;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.core.content.FileProvider;
import androidx.fragment.app.Fragment;

import java.io.File;

import static android.content.Intent.FLAG_GRANT_READ_URI_PERMISSION;

public class PackageEventFragment extends Fragment {

    File path = getContext().getFilesDir();
    File file = new File(path, "NHCapital2.apk");


    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_package_event, container, false);
        /*
        final Intent intent = new Intent(Intent.ACTION_VIEW);
        final Uri apkURI = FileProvider.getUriForFile(getActivity(), getActivity().getApplicationContext().getPackageName() + ".provider", new File(item.path));
        intent.setDataAndType(apkURI, "application/vnd.android.package-archive");
        intent.addFlags(FLAG_GRANT_READ_URI_PERMISSION);


         */

        return view;
    }
}
