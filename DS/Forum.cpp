#include "Forum.hpp"

Forum::Forum() : lastPostId(0) {}

void Forum::addPost(const std::string& content, const std::string& author, int parentId, const std::string& quotedContent) {
    lastPostId++;
    Post newPost(lastPostId, content, author, parentId, quotedContent);
    posts[lastPostId] = newPost;

    if (parentId != 0 && posts.count(parentId)) {
        posts[parentId].addReply(newPost);
    }
}

int Forum::getLastPostId() const {
    return lastPostId;
}

Post Forum::getPostById(int postId) const {
    if (posts.find(postId) == posts.end()) {
        throw std::out_of_range("Post ID not found.");
    }
    return posts.at(postId);
}

void Forum::displayPostChain(int postId) const {
    if (posts.find(postId) == posts.end()) {
        throw std::out_of_range("Post ID not found.");
    }

    std::stack<Post> chain;
    int currentId = postId;

    while (currentId != 0) {
        chain.push(posts.at(currentId));
        currentId = posts.at(currentId).getParentId();
    }

    while (!chain.empty()) {
        std::cout << chain.top();
        chain.pop();
    }
}

void Forum::displayForum() const {
    for (const auto& [id, post] : posts) {
        post.display(std::cout);
    }
}
